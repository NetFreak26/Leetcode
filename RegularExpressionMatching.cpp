class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();

        int m = p.size();

        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));

        dp[0][0] = true;

        for(int i=1; i<m; i++) {
            if(p[i] == '*') {
                dp[i+1][0] = dp[i-1][0];
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {

                if(p[i] == s[j] || p[i] == '.') {
                    dp[i+1][j+1] = dp[i][j];
                } else if(p[i] == '*') {
                    if(p[i-1] == '.' || p[i-1] == s[j]) {
                        dp[i+1][j+1] = dp[i][j] || dp[i-1][j+1] || dp[i][j+1] || dp[i+1][j];
                    } else {
                        dp[i+1][j+1] = dp[i-1][j+1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
