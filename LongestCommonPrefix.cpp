class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = strs[0];

        int n = strs.size();

        for(int i=1; i<n; i++) {
            int l = 0;

            while(l < common.size() && l < strs[i].size() && common[l] == strs[i][l]) {
                l++;
            }

            common = common.substr(0, l);
        }

        return common;
    }
};
