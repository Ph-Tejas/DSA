class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0, maxLen = 1;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // length 1
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length 2
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                st = i;
                maxLen = 2;
            }
        }

        // length >= 3
        for(int diff = 2; diff < n; diff++) {
            for(int i = 0; i < n - diff; i++) {
                int j = i + diff;

                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;

                    if(diff + 1 > maxLen) {
                        st = i;
                        maxLen = diff + 1;
                    }
                }
            }
        }

        return s.substr(st, maxLen);
    }
};