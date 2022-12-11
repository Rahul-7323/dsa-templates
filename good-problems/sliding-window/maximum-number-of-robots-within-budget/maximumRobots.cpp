// Time Complexity = O(n), Space Complexity = O(n)
// Subarray + Some Property == Sliding Window

int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
    // we can solve this problem using sliding window technique
    
    // we can use a monotonic decreasing deque to keep track of greater elements in the window
    // Hence the overall time complexity will be O(n) amortized
    deque<int> mono;
    int l=0, n=chargeTimes.size(), result=0;
    long long sum = 0;
    
    for(int i=0; i<n; i++){
        sum += runningCosts[i];
        
        // we have to maintain a decreasing (non-increasing) deque
        while(not mono.empty() and mono.back() < chargeTimes[i]){
            mono.pop_back();
        }
        
        mono.push_back(chargeTimes[i]);
        
        // decrease the size of the window from the left side until the condition is satisfied
        while(l<=i and mono.front() + (i-l+1)*sum > budget){
            sum -= runningCosts[l];

            if(mono.front() == chargeTimes[l]){
                mono.pop_front();
            }

            l++;
        }
        
        result = max(result, i-l+1);
    }
    
    return result;
}
