class Solution {
public:
    string convert(string s, int numRows) {

        int n = s.size();

        if(numRows == 1) {
            return s;
        }

        string ans = "";

        for(int row = 0; row < numRows; row++) {
            int ind = row;

            int down = true;

            while(ind < n) {
                ans += s[ind];
                if(row == 0 || row == numRows-1) {
                    ind += 2 * (numRows - 1);
                } else if(down) {
                    ind += 2 * (numRows - row - 1);
                    down = false;
                } else {
                    ind += 2 * row;
                    down = true;
                }
            }
        }

        return ans;
    }
};
