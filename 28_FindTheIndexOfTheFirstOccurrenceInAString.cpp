class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        while (i + m <= n) {
            int j = 0;
            while (j < m && haystack[i+j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
            i++;
        }
        return -1;
    }
};
