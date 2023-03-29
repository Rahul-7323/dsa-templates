/*
 * Given two strings s1 and s2, find the minimum number of operations to convert string s1 to string s2.
 * We can either delete a character, insert a character or replace a character any number of times
 * each operation costs 1 unit.
 *
 * Time Complexity = O(m * n)
 * Space Complexity = O(m * n)
 */

// top-down
int editDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();

    vector<vector<int>> memo(m+1, vector<int>(n+1, -1));

    function<int(int,int)> solve = [&](int i, int j) {
        if(i == 0 and j == 0) return 0;
        if(i == 0) return j;
        if(j == 0) return i;
        if(memo[i][j] != -1) return memo[i][j];

        // if both the characters are equal
        if(s1[i-1] == s2[j-1]) {
            return memo[i][j] = solve(i-1, j-1);
        }
        // else if the characters are not equal
        else {
            // we can either:-
            // 1. delete a character
            // 2. insert a character
            // 3. replace a character
            return memo[i][j] = 1 + min({solve(i-1, j), solve(i, j-1), solve(i-1, j-1)});
        }
    };

    return solve(m, n);
}

// bottom-up
int editDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i=0; i<=m; i++) {
        dp[i][0] = i;
    }

    for(int j=0; j<=n; j++) {
        dp[0][j] = j;
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    return dp[m][n];
}
