
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
// typedef tree<int, null_type, greater_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set1;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n=instructions.size();
        int mod=1e9+7;
        ordered_set st;
        long long ans=0;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int curr=instructions[i];
            int ct1=0,ct2=0;
            if(st.empty()){
                st.insert(curr);
                mp[curr]++;
                continue;
            }
            ct1=st.order_of_key(curr);


            
            ct2=st.size()-ct1-mp[curr];
            
            ans+=min(ct1,ct2);
            ans%=mod;
            st.insert(curr);
            mp[curr]++;




        }
        return ans;
    }
};