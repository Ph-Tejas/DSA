class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int, int> count;
        count.reserve(planks.size());

        int answer = 0;

        for (int plank : planks)
            answer = max(answer, ++count[plank]);

        vector<pair<int, int>> values;
        values.reserve(count.size());

        for (const auto &p : count)
            values.push_back(p);

        unordered_map<int, int> sumFreq;
        sumFreq.reserve(values.size() * values.size());

        int distinct = values.size();

        for (int i = 0; i < distinct; ++i) {
            auto &[x1, c1] = values[i];

            for (int j = i; j < distinct; ++j) {
                auto &[x2, c2] = values[j];

                if (i == j)
                    sumFreq[x1 + x2] += c1 / 2;
                else
                    sumFreq[x1 + x2] += min(c1, c2);
            }
        }

        for (const auto &[sum, pairs] : sumFreq)
            answer = max(answer, pairs + count[sum]);

        return answer;
    }
};