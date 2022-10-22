
string minWindow(string s, string t) {
    // we can solve this question using hashmap and sliding window technique

    // find the frequency of each character in t
    unordered_map<char,int> freq;

    for(char& c : t) freq[c]++;

    unordered_map<char,int> temp;
    int ml=0, mr=INT_MAX, l=0, count=0;

    for(int i=0; i<s.size(); i++) {
        // if the current character is present in t
        if(freq.count(s[i])) {
            // add the character to the current window
            temp[s[i]]++;
            // increment the count only if its frequency in the window is less than its frequency in t
            if(temp[s[i]] <= freq[s[i]]) count++;

            // remove any extra characters from the beginning
            while(l<=i) {
                // if the current character is present in t
                if(freq.count(s[l])) {
                    // if it is a redundant character
                    if(temp[s[l]] > freq[s[l]]) temp[s[l]]--;
                    // or else we can't remove the character from the beginning, hence break
                    else break;
                }

                l++;
            }

            // if all characters of t is present in the current window
            if(count==t.size() and mr-ml > i+1-l) {
                ml = l;
                mr = i+1;
            }
        }
        // if the window is empty
        else if(count == 0) l++;
    }

    if(mr == INT_MAX) return "";
    return s.substr(ml, mr-ml);
}
