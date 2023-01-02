/*
 * Author: Rahul M <roboto7o32oo3@gmail.com>
 * Date: 02-01-2023
 *
 * A difference array can be used to perform multiple range updates where we access the final values only after
 * performing all the queries.
 *
 * We can perform each range update in O(1) time and it is only when we have to access the final values we do a 
 * O(n) operation to compute the final values.
 *
 * Time Complexity: O(n) (O(1) for each query and then final computation is O(n))
 * Space Complexity: O(n)
 */

class DiffArray {
public:
    vector<int> diff;

    DiffArray(int n) {
        diff.resize(n+1, 0);
    }

    void update(int l, int r, int val) {
        if(l>r or r>=diff.size()-1) return;
        diff[l] += val;
        diff[r+1] -= val;
    }

    void prepare() {
        for(int i=1; i<diff.size(); i++) {
            diff[i] += diff[i-1];
        }
        
        diff.pop_back();
    }
};
