class Solution {
public:
    int n;
    vector<string> A;
    vector<vector<int>> overlap;
    vector<vector<int>> dp;
    vector<vector<int>> parent;

    int solve(int mask, int last) {
        if (dp[mask][last] != -1) return dp[mask][last];
        int pmask = mask ^ (1 << last);
        if (pmask == 0) return dp[mask][last] = 0;

        int best = 0, par = -1;

        for (int i = 0; i < n; i++) {
            if (pmask & (1 << i)) {
                int val = solve(pmask, i) + overlap[i][last];
                if (val > best) {
                    best = val;
                    par = i;
                }
            }
        }

        parent[mask][last] = par;
        return dp[mask][last] = best;
    }

    string shortestSuperstring(vector<string>& words) {
        A = words;
        n = A.size();

        overlap.assign(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int m = min(A[i].size(), A[j].size());
                for (int k = m; k >= 0; k--) {
                    if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        int FULL = 1 << n;
        dp.assign(FULL, vector<int>(n, -1));
        parent.assign(FULL, vector<int>(n, -1));

        int best = 0, last = 0;

        for (int i = 0; i < n; i++) {
            int val = solve(FULL - 1, i);
            if (val > best) {
                best = val;
                last = i;
            }
        }

        vector<int> perm;
        vector<bool> seen(n, false);

        int mask = FULL - 1;

        while (last != -1) {
            perm.push_back(last);
            seen[last] = true;
            int p = parent[mask][last];
            mask ^= (1 << last);
            last = p;
        }

        reverse(perm.begin(), perm.end());

        for (int i = 0; i < n; i++)
            if (!seen[i]) perm.push_back(i);

        string ans = A[perm[0]];

        for (int i = 1; i < n; i++) {
            int ov = overlap[perm[i - 1]][perm[i]];
            ans += A[perm[i]].substr(ov);
        }

        return ans;
    }
};