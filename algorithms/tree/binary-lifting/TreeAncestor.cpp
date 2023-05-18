/*
 * Binary Lifting is a technique that can be used for finding the Kth ancestor of a tree node in log(n) time.
 *
 * It does so by preprocessing to find up[0..n-1][0..log(n)]
 *
 * up[i][j] is the (2^j)th ancestor of the ith node.
 *
 * Preprocessing time : O(n * log(n))
 * Querying time: O(log(n))
 *
 */

class TreeAncestor {
public:
    vector<vector<int>> up;
    int n, d;

    TreeAncestor(int n, vector<int>& parent) {
        this->n = n;
        d = 32 - __builtin_clz(n);

        up = vector<vector<int>>(n, vector<int>(d, -1));

        for(int u=0; u<n; u++) {
            up[u][0] = parent[u];
        }

        for(int j=1; j<d; j++) {
            for(int u=0; u<n; u++) {
                if(up[u][j-1] != -1) {
                    up[u][j] = up[up[u][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        assert(node >= 0 and node < n);

        if(k >= 1<<d) return -1;

        for(int j=d-1; j>=0; j--) {
            if(k & (1<<j)) {
                node = up[node][j];

                if(node == -1) break;
            }
        }

        return node;
    }
};
