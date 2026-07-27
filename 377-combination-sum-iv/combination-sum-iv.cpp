class Solution {
public:
    vector<int>dp;
    int n;
    int fun(vector<int>&nums,int target){
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int i=0;i<n;i++){

            if(target-nums[i]<0)break;
            ans+=fun(nums,target-nums[i]);
        }
        return dp[target]=ans;


    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        dp.resize(target+1,-1);
        sort(nums.begin(),nums.end());
        
        return fun(nums,target);
    }
};