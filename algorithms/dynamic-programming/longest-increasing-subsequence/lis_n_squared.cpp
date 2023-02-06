/*
 * Author: Rahul M
 * Date: 06-02-2023
 *
 * Function for finding the longest (strictly) increasing subsequence.
 *
 * Time Complexity = O(n^2)
 * Space Complexity = O(n)
 */

int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
