
int lps(string& s) {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n));

    for(int i=0; i<n; ++i) {
        dp[i][i] = 1;
    }

    for(int i=0; i<n-1; ++i) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 2;
        }
        else {
            dp[i][i+1] = 1;
        }
    }

    for(int l=2; l<n; ++l) {
        for(int i=0, j=l; j<n; ++i, ++j) {
            if(s[i] == s[j]) {
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}
