// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/description/

int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    // we can solve this question using dynamic programming
    // we can think of this problem as unbounded knapsack dp
    const int INF = 1e6;

    int n = passingFees.size();

    // create an adjacency list
    vector<vector<vector<int>>> AList(n);

    for(vector<int>& edge : edges) {
        int u=edge[0], v=edge[1], w=edge[2];
        AList[u].push_back({v,w});
        AList[v].push_back({u,w});
    }

    vector<vector<int>> memo(n, vector<int>(maxTime+1, -1));

    function<int(int,int)> solve = [&](int u, int time) {
        // if we reach the destination
        if(u == n-1) return passingFees[n-1];
        if(memo[u][time] != -1) return memo[u][time];

        int result = INF;
        
        // try going to all the adjacent nodes
        for(vector<int>& edge : AList[u]) {
            int v=edge[0], w=edge[1];

            if(time+w <= maxTime) {
                result = min(result, passingFees[u]+solve(v, time+w));
            }
        }

        return memo[u][time] = result;
    };

    int ans = solve(0, 0);

    return ans == INF ? -1 : ans;
}
