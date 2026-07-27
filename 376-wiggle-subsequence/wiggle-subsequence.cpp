class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int fun(int i,int dir,vector<int>&nums){
        
        if(i+1==n)return 1;
        if(dp[i][dir]!=-1)return dp[i][dir];
        int ans;
        if(dir==0){
            if(nums[i]>nums[i+1]){
                ans=1+fun(i+1,!dir,nums);
            }
            else ans=fun(i+1,dir,nums);
        }
        else{
            if(nums[i]<nums[i+1]){
                ans=1+fun(i+1,!dir,nums);
            }
            else ans=fun(i+1,dir,nums);
        }
        return dp[i][dir]=ans;

    }
    int wiggleMaxLength(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector<int>(2,-1));
        return max(fun(0,0,nums),fun(0,1,nums));

        
    }
};