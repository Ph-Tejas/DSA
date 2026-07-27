class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        const int INF = INT_MAX;

        vector<array<int, 10>> v(n);
        for (int j = 0; j < 10; j++)
            v[n - 1][j] = INF;

        for (int i = n - 2; i >= 0; i--) {
            v[i] = v[i + 1];
            v[i][num[i + 1] - '0'] = i + 1;
        }

        string fin;
        fin.reserve(n);

        for (int i = 0; i < n; i++) {
            int cur = num[i] - '0';

            for (int j = 0; j < 10; j++) {
                if (cur == j) {
                    fin.push_back(char('0' + j));
                    break;
                }

                int loc = v[i][j];
                if (loc - i <= k) {
                    k -= (loc - i);
                    i = loc;
                    fin.push_back(char('0' + j));
                    break;
                }
            }
        }

        while (k--)
            fin.pop_back();

        int pos = 0;
        while (pos < (int)fin.size() && fin[pos] == '0')
            pos++;

        if (pos == (int)fin.size())
            return "0";

        return fin.substr(pos);
    }
};