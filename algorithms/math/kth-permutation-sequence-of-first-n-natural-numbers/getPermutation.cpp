/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 16-12-2020
 *
 * This function can be used for finding the Kth permutation sequence of the first N natural numbers
 *
 */

string getPermutation(int n, int k) {
    // precalculate the factorials
    vector<int> factorial(n);
    factorial[0] = 1;

    for(int i=1; i<n; i++)
        factorial[i] = i*factorial[i-1];

    // decrement k
    k--;
    
    // add the numbers to a set
    set<int> nums;

    for(int i=1; i<=n; i++)
        nums.insert(i);

    vector<int> perm;

    for(int i=0; i<n; i++) {
        if(k >= factorial[n-i-1]) {
            int t = k/factorial[n-i-1];
            k = k%factorial[n-i-1];

            // find the digit
            int digit = *next(nums.begin(), t);
            nums.erase(digit);

            perm.push_back(digit);
        }
        else {
            perm.push_back(*nums.begin());
            nums.erase(nums.begin());
        }
    }

    string result;

    for(int& num : perm) {
        result.push_back('0' + num);
    }

    return result;
}
