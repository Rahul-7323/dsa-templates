/*
 * Author: Rahul M
 * Date: 06-02-2023
 *
 * Function for finding the longest (strictly) increasing subsequence.
 *
 * Time Complexity = O(n*log(n))
 * Space Complexity = O(n)
 */

int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = INT_MIN;

    for(int i=0; i<n; i++) {
        // do lower bound binary search
        // in the case of non-decreasing subsequence we have to do upper bound binary search
        int j = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();

        if(dp[j-1]<nums[i] and nums[i]<dp[j]) {
            dp[j] = nums[i];
        }
    }

    for(int i=n; i>0; i--) {
        if(dp[i] != INT_MAX) {
            return i;
        }
    }

    return 0;
}
