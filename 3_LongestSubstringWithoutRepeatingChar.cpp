class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_index;
        int l = 0;
        int i = 0;
        int n = s.size();
        int max_len = 0;
        while (i < n) {
            if (last_index.find(s[i]) == last_index.end() || last_index[s[i]] < l) {
                last_index[s[i]] = i;
            } else {
                max_len = max(max_len, i-l);
                l = last_index[s[i]] + 1;
                last_index[s[i]] = i;
            }
            i++;
        }
        max_len = max(max_len, n-l);
        return max_len;
    }
};
