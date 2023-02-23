/*
 * Given n coins of different denominations where we have infinite supply of each coin type and an amount,
 * find the minimum number of coins required to make up amount.
 *
 * Time Complexity = O(n * amount)
 * Space Complexity = O(n * amount) 
 *
 */

// top-down
int minCoins(vector<int>& coins, int amount) {
    int n = coins.size(), INF = 1e9;

    vector<vector<int>> memo(n+1, vector<int>(amount+1, -1));

    function<int(int,int)> solve = [&](int i, int j) {
        // if the amount is 0
        if(j == 0) return 0;
        // if there are no coins left 
        if(i == 0) return INF;
        // if we memoized the state
        if(memo[i][j] != -1) return memo[i][j];

        // don't consider the current coin
        int result = solve(i-1, j);

        // if we can consider the current coin
        if(j >= coins[i-1]) {
            // consider the current coin
            result = min(result, 1 + solve(i, j - coins[i-1]));
        }

        return memo[i][j] = result;
    };

    return solve(n, amount);
}

// bottom-up
int minCoins(vector<int>& coins, int amount) {
    int n = coins.size(), INF = 1e9;

    vector<vector<int>> dp(n+1, vector<int>(amount+1));

    // base cases
    // when there are no coins
    for(int i=0; i<=amount; i++) {
        dp[0][i] = INF;
    }

    // when the amount is 0
    for(int i=0; i<=n; i++) {
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=amount; j++) {
            // don't consider the current coin
            dp[i][j] = dp[i-1][j];

            // if we can consider the current coin
            if(j >= coins[i-1]) {
                // consider the current coin
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }

    return dp[n][amount];
}
