/*
 * Author: Rahul M
 * Date: 07-02-2023
 *
 * Segment tree with lazy propagation for solving problems involving range queries and range updates.
 * The values in the nodes are updated lazily as an when needed which allows range updates in log(n) time.
 * This code can be easily modified for solving different types of problems.
 *
 * Time Complexity:-
 *      Range Query = O(log(n))
 *      Range Update = O(log(n))
 *
 * Space Complexity = O(n)
 */

template <typename T=int>
class SegmentTree {
    vector<T> st;
    vector<T> lazy;
    int n;
    T no_overlap_value = INT_MAX;

    int left(int i) {
        return 2*i + 1;
    }

    int right(int i) {
        return 2*i + 2;
    }

    T operate(T a, T b) {
        return min(a, b);
    }

    void pull(int i) {
        st[i] = operate(st[left(i)], st[right(i)]);
    }

    void push(int ss, int se, int si) {
        if(lazy[si] != 0) {
            st[si] += lazy[si];

            if(ss != se) {
                lazy[left(si)] += lazy[si];
                lazy[right(si)] += lazy[si];
            }

            lazy[si] = 0;
        }
    }

    void build(int ss, int se, int si, vector<T>& arr) {
        if(ss == se) {
            st[si] = arr[ss];
            return;
        }

        int mid = (ss + se) / 2;

        build(ss, mid, left(si), arr);
        build(mid+1, se, right(si), arr);

        pull(si);
    }

    T query(int qs, int qe, int ss, int se, int si) {
        push(ss, se, si);

        if(ss > qe or se < qs) return no_overlap_value;

        if(ss >= qs and se <= qe) return st[si];

        int mid = (ss + se) / 2;

        int left_val = query(qs, qe, ss, mid, left(si));
        int right_val = query(qs, qe, mid+1, se, right(si));

        return operate(left_val, right_val);
    }

    void update(int qs, int qe, T val, int ss, int se, int si) {
        push(ss, se, si);

        if(ss > qe or se < qs) return;

        if(ss >= qs and se <= qe) {
            lazy[si] += val;
            push(ss, se, si);
            return;
        }

        int mid = (ss + se) / 2;

        update(qs, qe, val, ss, mid, left(si));
        update(qs, qe, val, mid+1, se, right(si));

        pull(si);
    }

public:
    SegmentTree(int n) {
        this->n = n;
        st.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    SegmentTree(vector<T>& arr) : SegmentTree(arr.size()) {
        build(0, n-1, 0, arr);
    }

    T query(int qs, int qe) {
        return query(qs, qe, 0, n-1, 0);
    }

    T query(int i) {
        return query(i, i);
    }

    void update(int qs, int qe, T val) {
        update(qs, qe, val, 0, n-1, 0);
    }

    void update(int i, T val) {
        update(i, i, val);
    }
};
