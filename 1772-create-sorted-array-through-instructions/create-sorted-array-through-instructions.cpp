#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        int mod = 1e9 + 7;

        ordered_set st;
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int curr = instructions[i];

            // count strictly smaller
            int ct1 = st.order_of_key({curr, 0});

            // count strictly greater
            int ct2 = st.size() - st.order_of_key({curr, INT_MAX});

            ans = (ans + min(ct1, ct2)) % mod;

            st.insert({curr, i}); // unique index
        }

        return ans;
    }
}; 