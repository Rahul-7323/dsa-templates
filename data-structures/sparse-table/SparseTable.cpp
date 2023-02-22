/*
 * Author: Rahul M
 * Date: 22-02-2023
 *
 * Sparse Table is a data structure that can be used for performing range maximum/minimum queries in O(1) time.
 * This can only be used for immutable arrays.
 *
 * Time Complexity:-
 *      Precomputation = O(n*log(n))
 *      Range Query = O(1)
 *
 * Space Complexity = O(n*log(n))
 *
 */

template <typename T=int>
class SparseTable {

public:
    vector<vector<T>> st;

    int log2_floor(int num) {
        return num ? __builtin_clz(1) - __builtin_clz(num) : -1;
    }

    SparseTable(vector<T>& arr) {
        int n = arr.size();
        int k = log2_floor(n);
        st = vector<vector<T>>(k+1, vector<T>(n));

        // build the sparse table
        st[0] = arr;

        // building in bottom-up manner using dynamic programming
        for(int i = 1; i <= k; i++) {
            for(int j = 0; j + (1 << i) <= n; j++) {
                // range minimum query, change min to max for performing range maximum query
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int i = log2_floor(r - l + 1);
        // range minimum query, change min to max for performing range maximum query
        return min(st[i][l], st[i][r - (1 << i) + 1]);
    }
};
