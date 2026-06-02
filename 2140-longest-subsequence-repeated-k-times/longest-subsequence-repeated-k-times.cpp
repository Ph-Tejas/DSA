class Solution {
public:
    vector<bool> vis;

    // CHANGED:
    // 1) string passed by reference instead of by value
    // 2) added "used" parameter so we don't call count(vis.begin(), vis.end(), true)
    void build(string &cur,
               vector<string> &toCheck,
               int &sz,
               vector<string> &available,
               int used) {

        if (used == sz) return;

        for (int j = 0; j < sz; j++) {
            if (vis[j]) continue;

            cur.push_back(available[j][0]);

            toCheck.push_back(cur);

            vis[j] = true;
            build(cur, toCheck, sz, available, used + 1);
            vis[j] = false;

            cur.pop_back();
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {

        int n = (int)s.size();

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<string> available;

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {

                // same logic as your code
                while (freq[i] / k != 0) {
                    string str;
                    str.push_back(char(i + 'a'));
                    available.push_back(str);
                    freq[i] -= k;
                }
            }
        }

        int sz = (int)available.size();

        vis.assign(sz, false);

        vector<string> toCheck;

        // CHANGED:
        // reserve some space to reduce reallocations
        toCheck.reserve(50000);

        for (int i = 0; i < sz; i++) {

            toCheck.push_back(available[i]);

            vis[i] = true;

            string cur = available[i];

            // CHANGED:
            // start with 1 used character
            build(cur, toCheck, sz, available, 1);

            vis[i] = false;
        }

        sort(toCheck.begin(), toCheck.end(),
             [](const string &a, const string &b) {
                 if (a.size() == b.size())
                     return a > b;
                 return a.size() > b.size();
             });

        sz = (int)toCheck.size();

        for (int i = 0; i < sz; i++) {

            int len = (int)toCheck[i].size();

            int it = 0;
            int ct = 0;

            for (int j = 0; j < n; j++) {

                if (s[j] == toCheck[i][it]) {
                    it++;

                    if (it == len) {
                        ct++;
                        it = 0;
                    }
                }
            }

            if (ct >= k)
                return toCheck[i];
        }

        return "";
    }
};