/*
 * Articulation points or cut vertices are vertices which when removed disconnects the graph or increases the number of components in the graph.
 *
 * Tarjans algorithm can be used for finding the articulation points of a graph.
 *
 * Time Complexity = O(V + E)
 * Space Complexity = O(V)
 *
 * where V is the number of vertices or nodes and E is the number of edges.
 *
 */

vector<int> articulationPoints(vector<vector<int>>& AList) {
    int n = AList.size();

    vector<int> parent(n, -1);
    vector<int> disc(n);
    vector<int> low(n);
    vector<bool> visited(n, false);
    vector<bool> isAP(n, false);
    int time = 0;

    function<void(int)> dfs = [&](int u) {
        disc[u] = low[u] = time++;
        visited[u] = true;
        int children = 0;

        for(int v : AList[u]) {
            if(not visited[v]) {
                children++;
                parent[v] = u;

                dfs(v);

                low[u] = min(low[u], low[v]);

                if(parent[u] != -1 and disc[u] <= low[v]) {
                    isAP[u] = true;
                }
            }
            else if(parent[u] != v) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if(parent[u] == -1 and children > 1) {
            isAP[u] = true;
        }
    };

    for(int u=0; u<n; u++) {
        if(not visited[u]) dfs(u);
    }

    vector<int> APs;

    for(int u=0; u<n; u++) {
        if(isAP[u]) APs.push_back(u);
    }

    return APs;
}
