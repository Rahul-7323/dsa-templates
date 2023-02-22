/*
 * Created By: Rahul M <roboto7o32oo3@gmail.com>
 *
 * A class for solving segment tree problems.
 *
 * This code is written for solving Range Sum Query problem, but can be modified easily for other types of segment tree problems. 
 */

template <typename T = int> 
class SegmentTree {
public:
    
    vector<T> st; // segment tree
    vector<T> arr; // input array
    int n; // size of the input array
	
	// MODIFIABLE
	T invalidValue = 0;
    
	int left(int ind) {
		return 2*ind + 1;
	}

	int right(int ind) {
		return 2*ind + 2;
	}

	// MODIFIABLE
	T operate(T a, T b){
		// value at a node will be sum of left and right node in the case of Range Sum Query
		return a + b;
	}

	// MODIFIABLE
	void pull(int ind) {
		st[ind] = operate(st[left(ind)], st[right(ind)]);
	}

    // building the segment tree
    void build(int l, int r, int ind){
        // if we have reached the leaf node
        if(l == r){
            st[ind] = arr[l];
            return;
        }
        
        int m = (l+r)/2;
        
        // build the left tree and right tree
        build(l, m, left(ind));
        build(m+1, r, right(ind));
        
        // the value at current node
        pull(ind);
    }
    
    // sum of values between i and j
    T query(int l, int r, int i, int j, int ind){
        // if (l, r) lies completely inside (i, j)
        if(l>=i and r<=j){
            return st[ind];
        }
        // if (l, r) lies completely outside (i, j)
        if(r<i or l>j){
            return invalidValue;
        }
        
        int m = (l+r)/2;

		// call the function recursively for left and right child
		T leftVal = query(l, m, i, j, left(ind));
		T rightVal = query(m+1, r, i, j, right(ind));

        return operate(leftVal, rightVal);
    }
    
    // updating the value in segment tree
    void update(int l, int r, T val, int i, int ind){
		// if you reach a leaf node
		if(l == r){
			// if you reach node with index i
			if(l == i){
				st[ind] = val;
                arr[l] = val;
			}
			return;
		}
        // if i lies completely outside (l, r)
        if(i<l or i>r){
            return;
        }
        
        // if the current node is not a leaf node
        if(l != r){
            int m = (l+r)/2;
            update(l, m, val, i, left(ind));
            update(m+1, r, val, i, right(ind));
			pull(ind);
        }
    }
    
    SegmentTree(vector<T>& nums) {
        n = nums.size();
        arr = nums;
        st = vector<T>(4*n);
        
        // build the segment tree
        build(0, n-1, 0);
    }

    SegmentTree(int n) {
        this->n = n;
        arr = vector<T>(n, 0);
        st = vector<T>(4*n);

        // build the segment tree
        build(0, n-1, 0);
    }
    
    void update(int index, T val) {
        arr[index] = val;
        update(0, n-1, val, index, 0);
    }
    
    T query(int left, int right) {
        return query(0, n-1, left, right, 0);
    }
};
