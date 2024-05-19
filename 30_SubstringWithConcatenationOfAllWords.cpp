class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> freq;
        for (string &word: words) {
            freq[word]++;
        }

        int n = s.size();
        int m = words[0].size();
        int len = words.size() * m;

        vector<int> ans;
        
        for (int k=0; k<m; k++) {
            int i = k;
            int j = i;
            while (j + m <= n) {
                string temp = s.substr(j, m);
                if (freq[temp] > 0) {
                    freq[temp]--;
                    j += m;
                } else {
                    string first = s.substr(i, m);
                    freq[first]++;
                    i += m;
                }

                if (j - i == len) {
                    ans.push_back(i);
                }
            }

            while (i < j) {
                string first = s.substr(i, m);
                freq[first]++;
                i += m;
            }
        }
        return ans;
    }
};
