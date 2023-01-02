/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 02-01-2023
 *
 * A function for finding the next lexicographically greater permutation of the given array.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

void nextPermutation(vector<int> arr) {
    // find the index of the rightmost peak
    int peakInd = 0;

    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > arr[i-1]) {
            peakInd = i;
        }
    }

    // if the array is in decreasing order
    if(peakInd == 0) {
        // reverse the array and return 
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the index of the smallest element to the right side of the peak
    // that is greater than arr[peakInd-1]
    int nextGreaterInd = peakInd;

    while(nextGreaterInd+1<arr.size() and arr[nextGreaterInd+1]>arr[peakInd-1]) {
        nextGreaterInd++;
    }

    // swap arr[nextGreaterInd] and arr[peakInd-1]
    swap(arr[nextGreaterInd], arr[peakInd-1]);

    // reverse the elements to the right side of the peak
    reverse(arr.begin()+peakInd, arr.end());
} 
