/*
 * Author: Rahul M
 * Date: 04-02-2023
 *
 * Difference Matrix can be used in problems in which we have to perform multiple submatrix update queries 
 * such as adding a value k to all the elements in the submatrix starting at (x1, y1) and ending at (x2, y2) 
 * and we access the values in the matrix only after performing all the queries
 *
 * We can perform a submatrix update in O(1) time and it is only when we need to access the final values we
 * do a O(m*n) computation
 *
 * Time Complexity:-
 *      update = O(1)
 *      prepare = O(m*n)
 *
 * Space Complexity = O(m*n)
 */

class DiffMatrix {
public:
    vector<vector<int>> diff;
    int m, n;

    DiffMatrix(int m, int n) {
        this->diff = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        this->m = m;
        this->n = n;
    }

    void update(int x1, int y1, int x2, int y2, int val) {
        diff[x1][y1] += val;
        diff[x1][y2+1] -= val;
        diff[x2+1][y1] -= val;
        diff[x2+1][y2+1] += val;
    }

    void prepare() {
        for(int i=0; i<=m; i++) {
            for(int j=0; j<n; j++) {
                diff[i][j+1] += diff[i][j];
            }
        }

        for(int j=0; j<=n; j++) {
            for(int i=0; i<m; i++) {
                diff[i+1][j] += diff[i][j];
            }
        }
    }
};
