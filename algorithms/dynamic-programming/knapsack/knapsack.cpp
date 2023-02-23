/*
 * Given n items with their weights and values and a knapsack with a weight capacity of W, 
 * find the maximum value that we can get by choosing a subset of items such that the sum of weights
 * of the chosen subset of items is less than or equal to W. Repetition of items is not allowed.
 *
 * Time Complexity = O(n * W)
 * Space Complexity = O(n * W)
 *
 */

// top-down
int knapsack(vector<int>& weight, vector<int>& price, int W) {
    int n = weight.size();

    vector<vector<int>> memo(n+1, vector<int>(W+1, -1));

    function<int(int,int)> solve = [&](int i, int j) {
        // if there are no items or the capacity is 0
        if(i==0 or j==0) return 0;
        // if we memoized the state
        if(memo[i][j] != -1) return memo[i][j];

        int result = 0;

        // don't include the current item
        result = solve(i-1, j);

        // if it possible to include the current item in the knapsack
        if(j >= weight[i-1]) {
            // include the current item
            result = max(result, solve(i-1, j-weight[i-1]) + price[i-1]);
        }

        return memo[i][j] = result;
    };

    return solve(n, W);
}


// bottom-up
int knapsack(vector<int>& weight, vector<int>& price, int W) {
    int n = weight.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1));

    // if there are no items
    for(int i=0; i<=W; i++) {
        dp[0][i] = 0;
    }

    // if the capacity of the knapsack is 0
    for(int i=0; i<=n; i++) {
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            // if we can include the current item
            if(j >= weight[i-1]) {
                // we can either include the current item or not include it
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i-1]] + price[i-1]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}
