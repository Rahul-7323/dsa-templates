/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 09-01-2023 
 *
 * This function can be used for finding the minimum number of swaps required to sort an array.
 * The given array can be thought of as a graph were the edges are between elements and their actual indices.
 * The graph will contain non-intersecting cycles and each cycle is a strongly connected component.
 * The minimum number of swaps to sort the elements in a cycle is (cycle length - 1).
 * Hence we can find the sum of (cycle length - 1) for all cycles.
 * This idea can be used for solving many complex problems such as https://codeforces.com/contest/1768/problem/D
 *
 * Time Complexity = O(n*log(n))
 * Space Complexity = O(n)
 */

int minSwaps(vector<int>& nums) {
    vector<pair<int,int>> arr;

    for(int i=0; i<nums.size(); i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    int count = 0;
    vector<bool> visited(nums.size(), false);

    for(int i=0; i<nums.size(); i++) {
        if(visited[i] or arr[i].second==i) continue;

        int len = 0;
        int pos = i;

        while(not visited[pos]) {
            visited[pos] = true;
            pos = arr[pos].second;
            len++;
        }

        count += len-1;
    }

    return count;
}
