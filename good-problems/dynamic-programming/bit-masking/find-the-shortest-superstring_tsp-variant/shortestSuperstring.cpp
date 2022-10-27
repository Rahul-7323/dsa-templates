string shortestSuperstring(vector<string>& words) {
    // we should solve this question using bitmasking dp
    int n = words.size();
    vector<vector<int>> cost(n, vector<int>(n));

    // find the length of the longest prefix which is also suffix for each pair of words
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int maxlen=0, l1=words[i].size(), l2=words[j].size();

            for(int x=max(0, l1-l2); x<l1; x++) {
                int y=0;

                while(x+y < l1) {
                    if(words[i][x+y] == words[j][y]) y++;
                    else break;
                }

                if(x+y == l1) {
                    maxlen = y;
                    break;
                }
            }

            cost[i][j] = maxlen;
        }
    }

    int memo[n][1<<n];
    memset(memo, -1, sizeof memo);

    // now we have to use bitmasking and find the answer
    function<int(int,int)> solve = [&](int i, int bitmask) {
        if(bitmask == ((1<<n)-1)) return memo[i][bitmask] = 0;
        if(memo[i][bitmask] != -1) return memo[i][bitmask];

        int result = 0;

        // from the current node, we can go to any unvisited node
        for(int j=0; j<n; j++) {
            // if the node is unvisited
            if(((bitmask>>j) & 1) == 0) {
                result = max(result, cost[i][j] + solve(j, bitmask|(1<<j)));
            }
        }

        return memo[i][bitmask] = result;
    };

    // we can start from any node
    int maxval = 0;

    for(int i=0; i<n; i++) {
        maxval = max(maxval, solve(i, 1<<i));
    }

    for(int i=0; i<n; i++) {
        if(maxval == memo[i][1<<i]) {
            // use the memo table to find the result
            string result = words[i];
            int curr=i, bitmask=1<<i;

            for(int t=1; t<n; t++) {
                for(int j=0; j<n; j++) {
                    if(((bitmask>>j) & 1) == 0) {
                        if(memo[curr][bitmask] == (cost[curr][j] + memo[j][bitmask|(1<<j)])) {
                            // add that string to the result
                            result += words[j].substr(cost[curr][j], words[j].size()-cost[curr][j]);
                            curr = j;
                            bitmask |= 1<<j;
                            break;
                        }
                    }
                }
            }

            return result;
        }
    }

    return "";
}
