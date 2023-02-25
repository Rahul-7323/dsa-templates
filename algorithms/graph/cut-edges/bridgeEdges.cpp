/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 17-12-2022
 *
 * Bridge edges or cut edges are edges which when removed disconnects the graph or increases the number of components in the graph.
 * Tarjans algorithm can be used for finding the brige edges in a graph in linear time.
 *
 * Time Complexity = O(V + E)
 * Space Complexity = O(V)
 * where V is the number of vertices or nodes and E is the number of edges.
 *
 */

vector<vector<int>> bridgeEdges(vector<vector<int>>& AList) {
    int n = AList.size();

    vector<int> parent(n, -1);
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    vector<bool> visited(n, false);

    vector<vector<int>> bridges;

    int time = 0;

    function<void(int)> dfs = [&](int u) {
        // assign low time and disc time to the node
        disc[u] = low[u] = time++;

        // mark the node as visited
        visited[u] = true;

        for(int v : AList[u]) {
            // if the node hasn't been visited
            if(not visited[v]) {
                parent[v] = u;

                dfs(v);

                // update the low time
                low[u] = min(low[u], low[v]);

                 // if there are no backedges to ancestors in subtree v
                if(disc[u] < low[v]) {
                    bridges.push_back({u, v});
                }
            }
            else if(parent[u] != v) {
                // we have found a backedge to some ancestor
                low[u] = min(low[u], disc[v]);
            }
        }
    };

    for(int i=0; i<n; i++) {
        if(not visited[i]) {
            dfs(i);
        }
    }

    return bridges;
}
