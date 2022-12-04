
bool isBipartite(vector<vector<int>>& AList) {
    int n = AList.size();

    queue<int> queue;
    vector<int> color(n, -1);

    // do BFS
    for(int i=0; i<n; i++) {
        // if the node hasn't been visited
        if(color[i] == -1) {
            // color the node
            color[i] = 0;
            queue.push(i);

            while(not queue.empty()) {
                int u = queue.front();
                queue.pop();

                for(int v : AList[u]) {
                    // if the node is not colored
                    if(color[v] == -1) {
                        // color the node with complementary color
                        color[v] = 1^color[u];
                        queue.push(v);
                    }
                    // else if the node v has the same color as node u
                    else if(color[v] == color[u]) return false;
                }
            }
        }
    }

    return true;
}
