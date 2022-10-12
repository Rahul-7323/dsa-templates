bool isAllocatable(vector<int>& position, int m, int mid) {
    // check if we can allocate m balls with minimum distance of mid

    // place the first ball in the first basket
    int count = 1;
    int prev = position[0];

    for(int i=1; i<position.size(); i++) {
        if(position[i]-prev >= mid) {
            count++;
            prev = position[i];
        }
    }

    return count >= m;
}

int maxDistance(vector<int>& position, int m) {
    // this problem is the same as aggressive cows problem in spoj
    // we can solve this problem using simple iteration and check if we can allocate the balls
    // the above appraoch would work but we could instead using upper bound binary search which reduces the time needed
    // to just O(n log n)

    // sort the positions in increasing order
    sort(position.begin(), position.end());

    // perform upper bound binary search
    int low=0, high=position.back()+1, mid;

    while(low<high) {
        mid = (low+high)/2;

        if(isAllocatable(position, m, mid)) low = mid+1;
        else high = mid;
    }

    return low-1;
}
