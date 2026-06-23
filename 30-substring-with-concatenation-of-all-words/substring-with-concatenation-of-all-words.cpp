class Solution {
public:
    int eachn;
    int mod = 1e9 + 7;
    vector<long long> powers;

    long long powy(long long a, long long p) {
        long long res = 1;

        while (true) {
            if (p & 1) {
                res *= a;
                res %= mod;
                p--;
            } else {
                if (p == 0) return res % mod;
                a *= a;
                a %= mod;
                p /= 2;
            }
        }

        return res % mod;
    }

    long long findHash(string &word) {
        long long ans = 0;

        for (int i = 0; i < word.size(); i++) {
            ans += (powers[i] * ((word[i] - 'a') + 1)) % mod;
            ans %= mod;
        }

        return ans;
    }

    vector<int> findSubstring(string s, vector<string>& words) {

        int n = words.size();
        eachn = words[0].size();

        if ((long long)s.size() < 1LL * n * eachn)
            return {};

        powers.resize(eachn + 1);

        for (int i = 0; i <= eachn; i++) {
            powers[i] = powy(27, i);
        }

        map<long long, int> nums;

        for (int i = 0; i < n; i++) {
            nums[findHash(words[i])]++;
        }

        int originalSize = s.size();

        string last = s.substr(originalSize - (eachn - 1));

        long long initialHash = findHash(last);

        vector<long long> snums(originalSize - eachn + 1);

        for (int i = originalSize - eachn; i >= 0; i--) {

            initialHash *= 27;
            initialHash %= mod;

            initialHash += ((s[i] - 'a') + 1);
            initialHash %= mod;

            snums[i] = initialHash;

            initialHash =
                ((initialHash -
                  (((long long)((s[i + eachn - 1] - 'a') + 1) *
                    powers[eachn - 1]) %
                   mod)) +
                 mod) %
                mod;
        }

        vector<int> ans;

        int totalLen = n * eachn;

        for (int i = 0; i + totalLen <= originalSize; i++) {

            bool flag = true;
            map<long long, int> mp = nums;

            for (int j = i; j < i + totalLen; j += eachn) {

                long long curr = snums[j];

                if (mp.find(curr) != mp.end()) {
                    mp[curr]--;

                    if (mp[curr] == 0)
                        mp.erase(curr);

                } else {
                    flag = false;
                    break;
                }
            }

            if (flag && mp.empty()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};