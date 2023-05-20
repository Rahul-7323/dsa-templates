/*
 * In a tree rooted at some node, the lowest common ancestor (LCA) of two nodes u and v is the furthest node from
 * the root that has both u and v as it's descendant. The problem of finding the LCA of two nodes in a tree 
 * efficiently can be reduced to a problem of range minimum query (RMQ) by performing an euler tour on the tree and
 * using a data structure for RMQ like segment tree or sparse table. 
 *
 * An euler tour of a tree is basically a DFS traversal on a tree that stores the order in which the nodes are 
 * visited along with the time at which a node is visited for the first time. With this information, we can find
 * all the nodes that are present in the path between any two nodes of the tree. By storing the depth of a node
 * along with its ID during the euler tour and by using an RMQ data structure, we can efficiently find the node
 * that has the least depth among all the nodes in the path between any two nodes of the tree. Consequently, the
 * node with the least depth is the LCA of the two nodes.
 *
 * Using a segment tree, we can find the LCA of two nodes in O(log(n)) per query, whereas using a sparse table we 
 * can find the LCA in O(1) per query. Since there won't be any updates on the segment tree, using a sparse table is  
 * preferable and the following implementation uses the same for performing RMQ.
 *
 * LCA can be used for solving many complex problems. One application of LCA is finding the distance between any
 * two nodes of a tree in O(1) time per query.
 *
 * Time Complexity:-
 *      Build = O(n*log(n))
 *      Query = O(1)
 *
 * Space Complexity = O(n*log(n))
 *
 * Problems:-
 *      1. https://www.codechef.com/problems/MIN_UGLY
 */

class LCA {
public:
    vector<int> depth, euler, first;
    vector<vector<int>> st;
    int n, m, k;

    LCA() {}

    // Initialize the class with the adjacency list of the tree and the root node.
    void init(vector<vector<int>>& AList, int root=0) {
        n = AList.size();
        depth.resize(n);
        first.resize(n);
        euler.clear();

        depth[root] = 0;
        dfs(root, -1, AList);

        build();
    }

    // Performs euler tour and computes the depth of each node.
    void dfs(int u, int parent, vector<vector<int>>& AList) {
        first[u] = euler.size();
        euler.push_back(u);

        for(int v : AList[u]) {
            if(v == parent) continue;
            depth[v] = 1 + depth[u];
            dfs(v, u, AList);
            euler.push_back(u);
        }
    }

    // Builds the sparse table.
    void build() {
        m = euler.size();
        k = __builtin_clz(1) - __builtin_clz(m);

        st.assign(k+1, vector<int>(m));

        copy(euler.begin(), euler.end(), st[0].begin());

        for(int i = 1; i <= k; i++) {
            for(int j = 0; j + (1<<i) <= m; j++) {
                int left = st[i-1][j];
                int right = st[i-1][j + (1<<(i-1))];

                st[i][j] = (depth[left] < depth[right] ? left : right);
            }
        }
    }

    // Range minimum query for the node with the least depth between the range l and r.
    int query(int l, int r) {
        int len = r-l+1;
        int i = __builtin_clz(1) - __builtin_clz(len);

        int left = st[i][l];
        int right = st[i][r - (1<<i) + 1];

        return depth[left] < depth[right] ? left : right;
    }

    // Lowest common ancestor of two nodes u and v.
    int lca(int u, int v) {
        assert(u>=0 and u<n and v>=0 and v<n);
        int left = first[u], right = first[v];
        if(left > right) swap(left, right);
        return query(left, right);
    }

    // Distance between two nodes u and v.
    int distance(int u, int v) {
        assert(u>=0 and u<n and v>=0 and v<n);
        return depth[u] + depth[v] - 2*depth[lca(u, v)];
    }
};
