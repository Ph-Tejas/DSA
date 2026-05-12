 vector<vector<int>> divisors;
    bool built;
    void build() {
        divisors.resize(100001);

        for (int i = 1; i <= 100000; i++) {
            for (int j = i; j <= 100000; j += i) {
                divisors[j].push_back(i);
            }
        }

        built = true;
    }
class Solution {
public:
    // static vector<vector<int>> divisors;
    // static bool built;
    // static void build() {
    //     divisors.resize(100001);

    //     for (int i = 1; i <= 100000; i++) {
    //         for (int j = i; j <= 100000; j += i) {
    //             divisors[j].push_back(i);
    //         }
    //     }

    //     built = true;
    // }

    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        if (!built) {
            build();
        }

        vector<int> st(1e5 + 1);
        for (int i = 0; i < n; i++) {
            st[nums[i]] = 1;
        }
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < divisors[nums[i]].size(); j++) {
                if (st[divisors[nums[i]][j]] == 1) {
                    nums[i] = divisors[nums[i]][j];
                    break;
                }
            }
            sum += nums[i];
        }
        return sum;
    }
};
// vector<vector<int>> Solution::divisors;
// bool Solution::built = false;