/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 08-12-2022
 *
 * Graham Scan is an algorithm for finding the convex hull of given points.
 * Convex hull is the region with the smallest perimeter that covers all the points.
 *
 * Time Complexity = O(n log n), where n is the number of points
 * Space Complexity = O(n)
 */

struct Point {
    double x,y;

    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

/* function for finding the orientation of given points a, b, c centered at b
 *
 * c
 * |
 * |
 * |
 * b--------a
 *
 * We can find the orientation of the points with the help of cross product of the vectors a-b and c-b
 *
 * a-b = (a.x-b.x, a.y-b.y)
 * c-b = (c.x-b.x, c.y-b.y)
 *
 * val = (a.x-b.x)*(c.y-b.y) - (c.x-b.x)*(a.y-b.y)
 *
 * val > 0 -> counter-clockwise
 * val < 0 -> clockwise
 * val = 0 -> collinear
 */
int orientation(Point a, Point b, Point c) {
    double val = (a.x - b.x)*(c.y - b.y) - (c.x - b.x)*(a.y - b.y);

    if(val > 0) return -1; // counter-clockwise
    if(val < 0) return 1; // clockwise
    return 0; // collinear
}

// function for checking if the given points are oriented counter clockwise
// has optional parameter for considering collinear points which is true by default
bool isCounterClockwise(Point a, Point b, Point c, bool includeCollinear=true) {
    int orient = orientation(a, b, c);

    return orient==-1 or (orient==0 and includeCollinear);
}

// function for checking if the given points are collinear
bool isCollinear(Point a, Point b, Point c) {
    return orientation(a, b, c) == 0;
}

// function for finding the convex hull of given points
vector<Point> grahamScan(vector<Point>& points, bool includeCollinear=true) {
    // 1. Find the bottom-left most point
    Point p0 = *min_element(points.begin(), points.end(), [](Point& a, Point& b) {
        if(a.y == b.y) return a.x < b.x;
        return a.y < b.y;
    });

    // 2. Sort the points in increasing order of polar angle with respect to p0
    sort(points.begin(), points.end(), [&](Point& a, Point& b) {
        // find the orientation of the points
        int orient = orientation(a, p0, b);

        // if the points are collinear, choose the point which is closer to p0
        if(orient == 0) {
            double dist1 = (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y);
            double dist2 = (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
            return dist1 < dist2;
        }

        return orient == -1;
    });

    // if we want to include collinear points in the result
    // then we have to reverse the last collinear part
    if(includeCollinear) {
        // reverse the last collinear segment, or else it won't get included in the result
        int i = points.size();

        while(i>0 and isCollinear(points.back(), p0, points[i-1])) i--;

        reverse(points.begin()+i, points.end());
    }

    vector<Point> result;

    // go through each point
    for(Point& point : points) {
        // while the points make a clockwise turn, keep popping them
        while(result.size()>1 and not isCounterClockwise(result.back(), result[result.size()-2], point, includeCollinear)) {
            result.pop_back();
        }

        result.push_back(point);
    }

    return result;
}
