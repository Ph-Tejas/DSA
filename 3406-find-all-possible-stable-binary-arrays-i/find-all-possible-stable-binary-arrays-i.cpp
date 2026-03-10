class Solution {
public:
    static const int MOD = 1000000007;

    int numberOfStableArrays(int z, int o, int limit) {
        // dp0[i][j] = ending with 0-run, dp1[i][j] = ending with 1-run
        vector<vector<int>> dp0(z+1, vector<int>(o+1, 0));
        vector<vector<int>> dp1(z+1, vector<int>(o+1, 0));
        // pref0[i][j] = sum_{t=0..j} dp0[i][t]
        // pref1[j][i] = sum_{t=0..i} dp1[t][j]  (we store as pref1[j][i] for convenience)
        vector<vector<int>> pref0(z+1, vector<int>(o+1, 0));
        vector<vector<int>> pref1(o+1, vector<int>(z+1, 0));

        // Base: treat empty as a neutral starter so first run can come from it.
        // This is safe when z>0 and o>0 (problem gives positive integers).
        dp0[0][0] = 1;
        dp1[0][0] = 1;
        pref0[0][0] = 1;
        pref1[0][0] = 1;

        int total = z + o;
        for (int s = 1; s <= total; ++s) {
            int i_min = max(0, s - o);
            int i_max = min(z, s);
            for (int i = i_min; i <= i_max; ++i) {
                int j = s - i;
                if (j < 0 || j > o) continue;

                // compute dp0[i][j] = sum_{t = max(0, i-limit) .. i-1} dp1[t][j]
                long long sum0 = 0;
                if (i >= 1) {
                    int L = max(0, i - limit);
                    int R = i - 1;
                    long long A = pref1[j][R];                      // sum dp1[0..R][j]
                    long long B = (L - 1 >= 0) ? pref1[j][L - 1] : 0; // sum dp1[0..L-1][j]
                    sum0 = (A - B) % MOD;
                    if (sum0 < 0) sum0 += MOD;
                }
                dp0[i][j] = (int)sum0;

                // update pref0 for this i at column j
                long long prev0 = (j - 1 >= 0) ? pref0[i][j - 1] : 0;
                pref0[i][j] = (int)((prev0 + dp0[i][j]) % MOD);

                // compute dp1[i][j] = sum_{t = max(0, j-limit) .. j-1} dp0[i][t]
                long long sum1 = 0;
                if (j >= 1) {
                    int L = max(0, j - limit);
                    int R = j - 1;
                    long long A = pref0[i][R];                      // sum dp0[i][0..R]
                    long long B = (L - 1 >= 0) ? pref0[i][L - 1] : 0;
                    sum1 = (A - B) % MOD;
                    if (sum1 < 0) sum1 += MOD;
                }
                dp1[i][j] = (int)sum1;

                // update pref1 for this j at index i
                long long prev1 = (i - 1 >= 0) ? pref1[j][i - 1] : 0;
                pref1[j][i] = (int)((prev1 + dp1[i][j]) % MOD);
            }
        }

        // final answer: arrays ending with 0-run or 1-run
        int ans = (dp0[z][o] + dp1[z][o]) % MOD;
        // If z==0 && o==0 (not in constraints) we'd have 2 because of the two base values; but
        // problem guarantees positive zero and one so it's fine.
        return ans;
    }
};