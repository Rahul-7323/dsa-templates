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

template <class T=int, class F=function<T(const T&, const T&)>>
class SparseTable {
public:
    vector<vector<T>> st;
    F func;

    int log2_floor(int num) {
        return num ? __builtin_clz(1) - __builtin_clz(num) : -1;
    }

    SparseTable(vector<T>& arr, const F& func) {
        int n = arr.size();
        int k = log2_floor(n);
        st = vector<vector<T>>(k+1, vector<T>(n));
        // provide the function as an argument to the constructor
        this->func = func;

        // build the sparse table
        st[0] = arr;

        // building in bottom-up manner using dynamic programming
        for(int i = 1; i <= k; i++) {
            for(int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int i = log2_floor(r - l + 1);
        return func(st[i][l], st[i][r - (1 << i) + 1]);
    }
};
