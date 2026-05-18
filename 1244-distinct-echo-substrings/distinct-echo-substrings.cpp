class Solution {
public:
    long long mod = 1e9 + 7;

    long long powy(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }

            a = (a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    long long getHash(
        int l,
        int r,
        vector<long long>& pref,
        vector<long long>& invPower
    ) {

        long long val = pref[r];

        if (l > 0) {
            val = (val - pref[l - 1] + mod) % mod;
        }

        return (val * invPower[l]) % mod;
    }

    int distinctEchoSubstrings(string text) {

        int n = text.size();

        vector<long long> power(n);
        vector<long long> invPower(n);

        power[0] = 1;

        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 27) % mod;
        }

        long long inv27 = powy(27, mod - 2);

        invPower[0] = 1;

        for (int i = 1; i < n; i++) {
            invPower[i] = (invPower[i - 1] * inv27) % mod;
        }

        vector<long long> pref(n);

        for (int i = 0; i < n; i++) {

            long long val = (text[i] - 'a' + 1);

            val = (val * power[i]) % mod;

            pref[i] = val;

            if (i > 0) {
                pref[i] = (pref[i] + pref[i - 1]) % mod;
            }
        }

        unordered_set<long long> fin;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                int len = j - i + 1;

                long long curHash = getHash(i, j, pref, invPower);

                for (int it = 1;; it++) {

                    int nl = i + (it * len);
                    int nr = j + (it * len);

                    if (nr >= n) {
                        break;
                    }

                    long long nextHash =
                        getHash(nl, nr, pref, invPower);

                    if (nextHash != curHash) {
                        break;
                    }

                    if (it & 1) {

                        fin.insert(
                            getHash(i, nr, pref, invPower)
                        );
                    }
                }
            }
        }

        return fin.size();
    }
};