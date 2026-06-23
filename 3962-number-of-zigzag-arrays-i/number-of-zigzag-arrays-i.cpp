class Solution {
public:
    static const int mod = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r + 5;

        vector<array<int,2>> prev(m), curr(m);

        // Base row: i = n-1
        for(int j = r; j >= l; j--) {
            prev[j][0] = prev[j + 1][0] + 1;
            if(prev[j][0] >= mod) prev[j][0] -= mod;
        }

        for(int j = l; j <= r; j++) {
            prev[j][1] = prev[j - 1][1] + 1;
            if(prev[j][1] >= mod) prev[j][1] -= mod;
        }

        // Remaining rows
        for(int i = n - 2; i >= 0; i--) {

            // Compute dp[i][j][1]
            for(int j = l; j <= r; j++) {
                long long val = curr[j - 1][1] + prev[j + 1][0];
                curr[j][1] = val % mod;
            }

            // Compute dp[i][j][0]
            for(int j = r; j >= l; j--) {
                long long val = curr[j + 1][0] + prev[j - 1][1];
                curr[j][0] = val % mod;
            }

            swap(prev, curr);

            // Clear curr for next iteration
            for(int j = l - 1; j <= r + 1; j++) {
                curr[j][0] = curr[j][1] = 0;
            }
        }

        return (prev[l][0] + prev[r][1]) % mod;
    }
};