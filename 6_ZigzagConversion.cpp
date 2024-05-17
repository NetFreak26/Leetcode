class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= numRows || numRows == 1) {
            return s;
        }
        string ans = "";

        for (int i=0; i<numRows; i++) {
            int j = i;
            bool down = true;
            while (j < n) {
                ans += s[j];
                if (i == 0 || i == numRows-1) {
                    j += 2 * (numRows-1);
                } else if (down) {
                    j += 2 * (numRows-1-i);
                    down = false;
                } else {
                    j += 2 * i;
                    down = true;
                }
            }
        }
        return ans;
    }
};
