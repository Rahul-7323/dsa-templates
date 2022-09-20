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
	int n;
	int d;
	vector<vector<int>> up;

	public:

	TreeAncestor(int n, vector<int>& parent) {
		this->n = n;
		d = ceil(log2(n));

		up = vector<vector<int>>(n, vector<int>(d, -1));

		for(int v=0; v<n; v++) {
			up[v][0] = parent[v];
		}

		for(int j=1; j<d; j++) {
			for(int v=0; v<n; v++) {
				if(up[v][j-1] != -1) {
					up[v][j] = up[up[v][j-1]][j-1];
				}
			}
		}
	}

	int getKthAncestor(int node, int k) {
		if(k >= n) {
			return -1;
		}

		for(int j=d-1; j>=0; j--) {
			if(k & (1<<j)) {
				node = up[node][j];

				if(node == -1) {
					return -1;
				}
			}
		}

		return node;
	}
};
