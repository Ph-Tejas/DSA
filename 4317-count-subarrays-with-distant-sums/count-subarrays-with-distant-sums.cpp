class Solution {
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n = nums.size();
        long long total = (long long)n * (n + 1) / 2;
        if (k == 0) return total;   // |sum-goal| >= 0 is always true

        long long L = (long long)goal - k, R = (long long)goal + k;

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        // coordinate compression
        vector<long long> sortedPrefix(prefix);
        sort(sortedPrefix.begin(), sortedPrefix.end());
        int m = sortedPrefix.size();

        auto rankLeft = [&](long long x) {
            return (int)(lower_bound(sortedPrefix.begin(), sortedPrefix.end(), x) - sortedPrefix.begin());
        };
        auto rankRight = [&](long long x) {
            return (int)(upper_bound(sortedPrefix.begin(), sortedPrefix.end(), x) - sortedPrefix.begin());
        };

        // segment tree (point update / range count), inline
        vector<long long> tree(2 * m, 0);
        auto update = [&](int i) {
            i += m;
            tree[i] += 1;
            for (i /= 2; i >= 1; i /= 2)
                tree[i] = tree[2 * i] + tree[2 * i + 1];
        };
        auto query = [&](int l, int r) { // sum over half-open [l, r)
            long long res = 0;
            l += m; r += m;
            while (l < r) {
                if (l & 1) res += tree[l++];
                if (r & 1) res += tree[--r];
                l /= 2; r /= 2;
            }
            return res;
        };

        long long close = 0;
        update(rankLeft(prefix[0]));

        for (int j = 1; j <= n; j++) {
            long long hi = prefix[j] - L;   // exclusive upper bound on P[i]
            long long lo = prefix[j] - R;   // exclusive lower bound on P[i]
            close += query(rankRight(lo), rankLeft(hi));
            update(rankLeft(prefix[j]));
        }

        return total - close;
    }
};