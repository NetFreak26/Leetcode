class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int len = 1;

        for (int i=0; i<n; i++) {
            int x = i;
            int y = i + 1;
            while (x >=0 && y < n && s[x] == s[y]) {
                x--;
                y++;
            }
            if ((y - x - 1) > len) {
                l = x + 1;
                len = y - x - 1;
            }

            x = i;
            y = i;
            while (x >=0 && y < n && s[x] == s[y]) {
                x--;
                y++;
            }
            if ((y - x - 1) > len) {
                l = x + 1;
                len = y - x - 1;
            }
        } 
        return s.substr(l, len);
    }
};
