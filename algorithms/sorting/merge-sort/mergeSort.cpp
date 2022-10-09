/*
 * mergesort is a divide and conquer based stable sorting algorithm.
 *
 * mergesort can be used as a standard template for finding (i,j) pairs that satisfy some constraint.
 *
 * Time Complexity = O(n log(n))
 * Space Complexity = O(n)
 */

template <typename T=int>
int merge(vector<T>& nums, int l, int r, int m){
	vector<T> temp(nums.begin()+l, nums.begin()+r);
	int count=0, i=l, j=m, k=l;
	
	/*-------------------------------*/
	// find the count of pairs (i,j) for some constraint over here
	while(i<m and j<r){
		if(nums[i] <= nums[j]){
			i++;
		}
		else{
			count += m-i;
			j++;
		}
	}
	/*--------------------------------*/
	
	i=l; j=m;
	
	// after finding the count, then do the merge process
	while(i<m and j<r){
		if(temp[i-l] <= temp[j-l]){
			nums[k] = temp[i-l];
			k++; i++;
		}
		else{
			nums[k] = temp[j-l];
			k++; j++;
		}
	}
	
	while(i<m){
		nums[k] = temp[i-l];
		k++; i++;
	}
	
	while(j<r){
		nums[k] = temp[j-l];
		k++; j++;
	}
	
	return count;
}

template <typename T=int>
int mergeSort(vector<T>& nums, int l, int r){
	if((r-l) <= 1){
		return 0;
	}
	
	int m = (l+r)/2;
	
	int c1 = mergeSort<T>(nums, l, m);
	int c2 = mergeSort<T>(nums, m, r);
	
	int c3 = merge<T>(nums, l, r, m);
	
	return c1+c2+c3;
}
