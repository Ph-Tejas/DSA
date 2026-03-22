class Solution {
public:

    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    unordered_map<pair<int,int>, int, hash_pair> mp;
    const int INF = INT_MAX / 2;

    int fun(int ind, int prev, vector<int>& arr1, vector<int>& arr2) {
        if (ind == arr1.size()) return 0;

        if (mp.count({ind, prev})) return mp[{ind, prev}];

        int changing = INF, notChanging = INF;

        auto it = upper_bound(arr2.begin(), arr2.end(), prev);

        if (it != arr2.end()) {
            changing = 1 + fun(ind + 1, *it, arr1, arr2);
        }

        if (arr1[ind] > prev) {
            notChanging = fun(ind + 1, arr1[ind], arr1, arr2);
        }

        return mp[{ind, prev}] = min(changing, notChanging);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int ans = fun(0, -1, arr1, arr2);
        return (ans >= INF) ? -1 : ans;
    }
};