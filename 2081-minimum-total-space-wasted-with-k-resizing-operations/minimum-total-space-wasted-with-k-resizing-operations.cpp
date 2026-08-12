class Solution {
public:
    int n;
    vector<int> pf;
    vector<vector<int>> dp;

    int fun(int i, int k, vector<int>& nums) {
        if (i == n)
            return 0;

        if (k < 0)
            return 1e9;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = 1e9;
        int mx = 0;

        for (int j = i; j < n; j++) {
            mx = max(mx, nums[j]);

            int sum = pf[j + 1] - pf[i];

            
            int waste = mx * (j - i + 1) - sum;

            ans = min(ans, waste + fun(j + 1, k - 1, nums));
        }

        return dp[i][k] = ans;
    }

    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n = nums.size();

        pf.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            pf[i + 1] = pf[i] + nums[i];

        dp.assign(n, vector<int>(k + 1, -1));

        return fun(0, k, nums);
    }
};