#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<long long,long long>,
    null_type,
    less<pair<long long,long long>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

long long timer = 0;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long ct=0;
        ordered_set st;
        long long n=nums.size();
        for(long long i=0;i<n;i++){
            st.insert({nums[i],i});            
        }
        
        for(long long i=n-1;i>-1;i--){
            long long curr=nums[i];
            pair<long long,long long>pr={curr,i};
            st.erase(pr);
            pr.second=-1;
            pr.first=(((long long)curr)*2)+1;
            long long x=st.order_of_key(pr);
            ct+=(st.size()-x);


        }
        return ct;


    }
};