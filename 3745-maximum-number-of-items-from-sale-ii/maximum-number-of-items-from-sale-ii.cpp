class Solution {
public:
    struct Node {
        double cost;
        int power;
        int price;
        int idx;
    };

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int mx = 0;
        for (auto &x : items) {
            mx = max(mx, x[0]);
        }

        vector<int> freq(mx + 1, 0);

        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
        }

        vector<int> possible(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            if (freq[i] == 0) continue;

            int ct = 0;

            for (int j = i; j <= mx; j += i) {
                ct += freq[j];
            }

            possible[i] = ct - 1;
        }

        vector<int> available(n);

        vector<Node> v;
        v.reserve(2 * n);

        for (int i = 0; i < n; i++) {
            available[i] = possible[items[i][0]];

            int price = items[i][1];

            v.push_back({(double)price, 1, price, i});

            if (available[i] > 0) {
                v.push_back({price / 2.0, 2, price, i});
            }
        }

        sort(v.begin(), v.end(), [](const Node& a, const Node& b) {
            if (a.cost != b.cost)
                return a.cost < b.cost;

            if (a.power != b.power)
                return a.power > b.power;

            return a.price < b.price;
        });

        int ans = 0;

        for (auto &cur : v) {
            long long power = cur.power;
            long long price = cur.price;
            int idx = cur.idx;

            if (power == 2) {
                if (price > budget) continue;

                long long avail = available[idx];
                long long totalCost = avail * price;

                if (totalCost <= budget) {
                    ans += avail * 2;
                    budget -= totalCost;
                } else {
                    long long can = budget / price;
                    ans += can * 2;
                    budget -= can * price;
                }
            } else {
                ans += budget / price;
                break;
            }
        }

        return ans;
    }
};