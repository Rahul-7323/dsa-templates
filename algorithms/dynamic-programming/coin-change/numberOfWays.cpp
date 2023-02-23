/*
 * Given n coins of different denominations where we have infinite supply of each coin type and an amount, find the number of ways
 * of choosing coins such that the sum of the values of the chosen coins add up to amount.
 *
 * Time Complexity = O(n * amount)
 * Space Complexity = O(n * amount) 
 *
 */

// top-down
int numberOfWays(vector<int>& coins, int amount) {
    int n = coins.size(), MOD = 1e9 + 7;
    
    vector<vector<int>> memo(n+1, vector<int>(amount+1, -1));

    function<int(int,int)> solve = [&](int i, int j) {
        // if the amount is 0
        if(j == 0) return 1;
        // if there are no coins left
        if(i == 0) return 0;
        // if we memoized the state
        if(memo[i][j] != -1) return memo[i][j];

        // don't consider the current coin
        int result = solve(i-1, j);

        // if we can include the current coin
        if(j >= coins[i-1]) {
            // consider the current coin
            result = (result + solve(i, j - coins[i-1]))%MOD;
        }

        return mod[i][j] = result;
    };

    return solve(n, amount);
}

// bottom-up
int numberOfWays(vector<int>& coins, int amount) {
    int n = coins.size(), MOD = 1e9 + 7;

    vector<vector<int>> dp(n+1, vector<int>(amount+1));

    // base cases
    // when there are no coins
    for(int i=0; i<=amount; i++) {
        dp[0][i] = 0;
    }

    // when the amount is 0
    for(int i=0; i<=n; i++) {
        dp[i][0] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=amount; j++) {
            // don't include the current coin
            dp[i][j] = dp[i-1][j];

            // if we can include the current coin
            if(j >= coins[i-1]) {
                // include the current coin
                dp[i][j] = (dp[i][j] + dp[i][j - coins[i-1]])%MOD;
            }
        }
    }

    return dp[n][amount];
}
