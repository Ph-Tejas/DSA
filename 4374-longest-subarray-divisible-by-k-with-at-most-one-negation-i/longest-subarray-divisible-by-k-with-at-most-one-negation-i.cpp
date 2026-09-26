class Solution {
public:
    vector<int> pf;
    vector<int> lastIdx, stamp;
    int curStamp = 0;
    int n, k;

    int fun(int l, vector<int>& nums) {
        if (l != -1) {
            nums[l] = (k - nums[l]) % k;
        }

        curStamp++;
        int a = 0;
        for (int i = 0; i < n; i++) {
            pf[i + 1] = (pf[i] + nums[i]) % k;
            a = (a + nums[i]) % k;
            lastIdx[a] = i;
            stamp[a] = curStamp;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int tobe = pf[i - 1];

            if (stamp[tobe] == curStamp && lastIdx[tobe] >= i - 1) {
                ans = max(ans, lastIdx[tobe] - (i - 1) + 1);
            }
        }
        if (l != -1) nums[l] = (k - nums[l]) % k;
        return ans;
    }

    int longestSubarray(vector<int>& nums, int K) {
        n = nums.size();
        k = K;
        pf.resize(n + 1);
        lastIdx.resize(k, -1);
        stamp.resize(k, -1);
        long long l = (long long)k * 10000000;
        for (int i = 0; i < n; i++) {
            long long l_ = l + nums[i];
            l_ %= k;
            nums[i] = (int)l_;
        }
        int ans = fun(-1, nums);
        for (int i = 0; i < n; i++) {
            ans = max(ans, fun(i, nums));
        }
        return ans;
    }
};