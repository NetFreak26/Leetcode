class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) {
            return strs[0];
        }
        string pre = "";
        int m = strs[0].size();
        int i = 0;
        while (i < m) {
            char c = strs[0][i];
            bool isPre = true;
            for (int j=1; j<n; j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    isPre = false;
                    break;
                }
            }
            if (isPre) {
                pre += c;
            } else {
                break;
            }
            i++;
        }
        return pre;
    }
};
