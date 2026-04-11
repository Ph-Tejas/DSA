class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>>mp(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &val:mp){
            if(val.size()>2){
                for(int i=0;i<val.size()-2;i++){
                    ans=min(ans,2*(val[i+2]-val[i]));
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};