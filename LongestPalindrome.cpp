class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        int start = 0;

        int n = s.size();

        for(int i=0; i<n; i++) {
            int l = i - 1;
            int r = i + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            if(maxLen < (r - l - 1)) {
                maxLen = r - l - 1;
                start = l + 1;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }

            if(maxLen < (r - l - 1)) {
                maxLen = r - l - 1;
                start = l + 1;
            }
        }

        return s.substr(start, maxLen);
    }
};
