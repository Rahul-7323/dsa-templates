
vector<int> dijkstras(int n, vector<vector<int>> edges, int source) {

    // create an adjacency list
    vector<vector<vector<int>>> AList(n);

    for(vector<int>& edge : edges) {
        int u=edge[0], v=edge[1], w=edge[2];

        AList[u].push_back({v,w});
        AList[v].push_back({u,w});
    }

    const int INF = 1e9;

    vector<int> distance(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while(not pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();

        int dist = top.first;
        int u = top.second;

        for(vector<int>& edge : AList[u]) {
            int v=edge[0], w=edge[1];

            if(distance[v] > dist+w) {
                distance[v] = dist+w;
                pq.push({dist+w, v});
            }
        }
    }

    return distance;
}
