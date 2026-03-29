class Solution {
public:
    int MOD = 1e9 + 7;

    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();

        vector<int> dsum(5001, 0);
        for(int i = 0; i <= 5000; i++) {
            int x = i;
            while(x > 0) {
                dsum[i] += (x % 10);
                x /= 10;
            }
        }

        vector<int> ans(5001, 0);
        ans[0] = 1;

        for(int i = 0; i < n; i++) {
            vector<int> tans(5001, 0);
            int pref = 0;

            for(int v = 0; v <= 5000; v++) {
                pref = (pref + ans[v]) % MOD;

                if(dsum[v] != digitSum[i]) continue;

                tans[v] = pref;
            }

            ans = tans;
        }

        int anss = 0;
        for(int v = 0; v <= 5000; v++) {
            anss = (anss + ans[v]) % MOD;
        }

        return anss;
    }
};