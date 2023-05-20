
int lps(string& s) {
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int result = 1;

    for(int i=0; i<n; ++i) {
        dp[i][i] = true;
    }

    for(int i=0; i<n-1; ++i) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            result = 2;
        }
    }

    for(int l=2; l<n; ++l) {
        for(int i=0, j=l; j<n; ++i, ++j) {
            if(s[i]==s[j] and dp[i+1][j-1]) {
                dp[i][j] = true;
                result = max(result, l+1);
            }
        }
    }

    return result;
}
