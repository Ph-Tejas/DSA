class Solution {
public:
    int stoneGameV(vector<int>& nums) {
        int n = nums.size();
        
        // prefix sum
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // dp[i][j] = max score from subarray [i, j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of interval
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                int best = 0;

                for (int k = i; k < j; k++) {
                    int leftSum  = pref[k + 1] - pref[i];
                    int rightSum = pref[j + 1] - pref[k + 1];

                    int score = 0;
                    if (leftSum < rightSum) {
                        score = leftSum + dp[i][k];
                    } else if (leftSum > rightSum) {
                        score = rightSum + dp[k + 1][j];
                    } else {
                        score = leftSum + max(dp[i][k], dp[k + 1][j]);
                    }

                    best = max(best, score);
                }

                dp[i][j] = best;
            }
        }

        return dp[0][n - 1];
    }
};
