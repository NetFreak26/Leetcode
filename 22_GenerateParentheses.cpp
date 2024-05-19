class Solution {
private:
    void generate(vector<string> &ans, string &temp, int open, int close, int n) {
        if (open > n | close > n | close > open) return;
        if (open == n && close == n) {
            ans.push_back(temp);
        }
        temp.push_back('(');
        generate(ans, temp, open+1, close, n);
        temp.pop_back();
        temp.push_back(')');
        generate(ans, temp, open, close+1, n);
        temp.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        generate(ans, temp, 0, 0, n);
        return ans;
    }
};
