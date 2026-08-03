class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            auto it=lower_bound(v.begin(),v.end(),nums[i]);
            if(it==v.end()){
                v.push_back(nums[i]);
            }
            else{
                v[it-v.begin()]=nums[i];
            }
        }
        if(v.size()>2)return true;
        return false;
    }
};