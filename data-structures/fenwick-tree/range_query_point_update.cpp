/*
 * Fenwick Tree, also called Binary Indexed Tree or BIT is a data structure that can be used for performing
 * range or point queries and updates. Fenwick Tree is mainly used for range queries for sums in an array.
 * The main advantage of Fenwick Tree is its ease of implementation when compared to segment tree and its 
 * linear space complexity. However, not all problems that can be solved using segment tree can be solved
 * using a Fenwick Tree. 
 *
 * This code is written for performing point updates and range queries for sum.
 *
 * Time Complexity:-
 *      Build = O(n*log(n))
 *      Query = O(log(n))
 *      Update = O(log(n))
 *
 * Space Complexity = O(n)
 */

template <typename T=int>
struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(int n) {
        this->n = n;
        bit.resize(n, 0);
    }

    FenwickTree(vector<T>& arr) : FenwickTree(arr.size()) {
        for(int i=0; i<n; i++) {
            add(i, arr[i]);
        }
    }

    T sum(int r) {
        T result = 0;
        while(r >= 0) {
            result += bit[r];
            r = (r & (r+1)) - 1;
        }
        return result;
    }

    T sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int i, T delta) {
        while(i < n) {
            bit[i] += delta;
            i = (i | (i + 1));
        }
    }
};
