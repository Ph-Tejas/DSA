class Solution {
public:
 int dp[32][2][2];

    int dfs(string &s, int i, int tight, int prev1) {
        if (i == s.size())
            return 1;

        if (dp[i][tight][prev1] != -1)
            return dp[i][tight][prev1];

        int limit = tight ? s[i] - '0' : 1;
        int res = 0;

        for (int bit = 0; bit <= limit; bit++) {
            if (prev1 && bit) continue;  // no consecutive 1s
            res += dfs(s, i + 1, tight && (bit == limit), bit);
        }

        return dp[i][tight][prev1] = res;
    }
    int findIntegers(int n) {
         string s = bitset<32>(n).to_string();
        s = s.substr(s.find('1'));

        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, 1, 0);
    }
};