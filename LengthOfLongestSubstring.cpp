class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ind;

        int lastMatchedIndex = -1;

        int maxLen = 0;

        for(int i=0; i<s.size(); i++) {
            if(ind.find(s[i]) == ind.end()) {
                maxLen = max(maxLen, i - lastMatchedIndex);
                ind[s[i]] = i;
            } else {
                if(lastMatchedIndex > ind[s[i]]) {
                    maxLen = max(maxLen, i - lastMatchedIndex);
                } else {
                    maxLen = max(maxLen, i - ind[s[i]]);
                    lastMatchedIndex = ind[s[i]];
                }
                ind[s[i]] = i;
            }
        }
        return maxLen;
    }
};
