/*
 * Given two strings s1 and s2, find the longest common subsequence between them.
 *
 * Time Complexity = O(m * n)
 * Space Complexity = O(m * n)
 */

// top-down
int lcs(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();

    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

    function<int(int,int)> solve = [&](int i, int j) {
        if(i == 0 or j == 0) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        if(s1[i-1] == s2[j-1]) return memo[i][j] = 1 + solve(i-1, j-1);
        return memo[i][j] = max(solve(i-1, j), solve(i, j-1));
    };

    return solve(m, n);
}

// bottom-up
int lcs(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}
