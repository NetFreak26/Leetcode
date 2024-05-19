class Solution {
private:
    string charToString(char x) {
        if (x == '2') {
            return "abc";
        }
        if (x == '3') {
            return "def";
        }
        if (x == '4') {
            return "ghi";
        }
        if (x == '5') {
            return "jkl";
        }
        if (x == '6') {
            return "mno";
        }
        if (x == '7') {
            return "pqrs";
        }
        if (x == '8') {
            return "tuv";
        }
        return "wxyz";
    }

    void findCombinations(string &digits, int ind, int n, string &s, vector<string> &ans) {
        if (ind == n) {
            ans.push_back(s);
            return;
        }
        string t = charToString(digits[ind]);

        for (char &c: t) {
            s.push_back(c);
            findCombinations(digits, ind+1, n, s, ans);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string s;
        int n = digits.size();
        if (n == 0) {
            return ans;
        }
        findCombinations(digits, 0, n, s, ans);
        return ans;
    }
};
