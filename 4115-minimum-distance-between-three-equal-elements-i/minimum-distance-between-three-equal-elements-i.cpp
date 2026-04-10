class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto &val:mp){
            if(val.second.size()>2){
                for(int i=0;i<val.second.size()-2;i++){
                    ans=min(ans,2*(val.second[i+2]-val.second[i]));
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};