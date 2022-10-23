class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // we can solve this question using bitmasking dp
        // placing the first element in the second slot and placing the second element in the first slot
        // placing the first element in the first slot and placing the second element in the second slot
        // in both of these cases, the visited array will be the same, slot 1 will have one element and slot 2 will have one element, hence we can simply use a bitmask to make them marked as visited
        // this is similar to a bitmasking dp question that I have solved previously

        int memo[1<<18][18];
        memset(memo, -1, sizeof memo);

        int n = nums.size();

        function<int(int,int)> solve = [&](int bitmask, int i) {
            // if all the numbers have been alloted
            if(i == n) return 0;
            if(memo[bitmask][i] != -1) return memo[bitmask][i];

            int result = 0;

            // try all the possible slots for the current number
            for(int s=0; s<numSlots; s++) {
                // if there is space left in the slot
                if((bitmask & (1<<(2*s + 1))) == 0) {
                    result = max(result, (nums[i] & (s+1)) + solve(bitmask+(1<<(2*s)), i+1));
                }
            }

            return memo[bitmask][i] = result;
        };

        return solve(0, 0);
    }
};
