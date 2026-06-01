class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        long long minPrice = LLONG_MAX;
        int mx = 0;

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, (long long)items[i][1]);
            mx = max(mx, items[i][0]);
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

        map<int, long long> groupedFreq;

        for (int i = 0; i < n; i++) {
            available[i] = possible[items[i][0]];

            int price = items[i][1];

            // same optimization as the accepted solution
            if (price >= 2 * minPrice) continue;

            if (available[i] > 0) {
                groupedFreq[price] += available[i];
            }
        }

        long long bonus = 0;
        long long currentBudget = budget;

        for (auto &[price, ct] : groupedFreq) {
            if (currentBudget < price) continue;

            long long canBuy = min(ct, currentBudget / price);

            currentBudget -= canBuy * price;
            bonus += canBuy;
        }

        long long base = currentBudget / minPrice;

        return (int)(2 * bonus + base);
    }
};