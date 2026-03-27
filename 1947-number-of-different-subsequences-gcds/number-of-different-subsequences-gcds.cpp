class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        vector<bool> present(maxi + 1, false);
        for (int x : nums) present[x] = true;

        int ct = 0;

        for (int i = 1; i <= maxi; i++) {
            int g = 0;

            for (int j = i; j <= maxi; j += i) {
                if (!present[j]) continue;

                g = __gcd(g, j);

                if (g == i) {
                    ct++;
                    break;
                }
            }
        }

        return ct;
    }
};