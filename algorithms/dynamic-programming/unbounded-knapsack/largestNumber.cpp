// https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/description/

string largestNumber(vector<int>& cost, int target) {
    int n = cost.size();
    vector<vector<int>> memo(n+1, vector<int>(target+1, -1));

    // unbounded knapsack with the price as 1 since we want to maximize the number of items
    function<int(int,int)> solve = [&](int i, int target) {
        if(target == 0) return memo[i][target] = 0;
        if(i == 0) return memo[i][target] = INT_MIN;
        if(memo[i][target] != -1) return memo[i][target];
        int result = solve(i-1, target);
        if(target >= cost[i-1]) result = max(result, 1+solve(i, target-cost[i-1]));
        return memo[i][target] = result;
    };

    if(solve(n, target) < 0) return "0";

    string result;
    int x=n, y=target;

    // DP Path Reconstruction
    while(x>0 and y>0) {
        if(y>=cost[x-1] and memo[x][y] == (1 + memo[x][y-cost[x-1]])) {
            result.push_back('0'+x);
            y -= cost[x-1];
        }
        else x--;
    }

    return result;
}
