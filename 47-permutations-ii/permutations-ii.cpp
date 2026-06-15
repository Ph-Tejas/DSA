class Solution {
public:
    unordered_map<int,int>mp;
    int n;
    void fun(vector<int>& nums,int i,vector<vector<int>>&ans,vector<int>v){
        if(i==n){
            ans.push_back(v);
        }
        for(auto &val:mp){
            if(val.second>0){
                val.second--;
                v.push_back(val.first);
                fun(nums,i+1,ans,v);
                v.pop_back();
                val.second++;
            }
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>ans;
        fun(nums,0,ans,{});
        return ans;
    }
};