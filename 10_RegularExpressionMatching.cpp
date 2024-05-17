class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
        dp[0][0] = true;

        for (int i=1; i<n; i+=2) {
            if (p[i] == '*') {
                dp[i+1][0] = true;
            } else {
                break;
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (p[i] == s[j] || p[i] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                } else if (p[i] == '*') {
                    if (p[i-1] == s[j] || p[i-1] == '.') {
                        dp[i+1][j+1] = dp[i][j] || dp[i][j+1] || dp[i+1][j] || dp[i-1][j+1];
                    } else {
                        dp[i+1][j+1] = dp[i-1][j+1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};
