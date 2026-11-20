class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int maxi=1;
        unordered_map<int,int>mp;
        vector<vector<int>>dp(n,vector<int>(2,1));
        mp[nums[0]]=1;
        mp[nums[0]+1]=1;
        for(int i=1;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end()){
                dp[i][0]=mp[nums[i]-1]+1;
            }
            if(mp.find(nums[i])!=mp.end()){
                dp[i][1]=mp[nums[i]]+1;
            }
            maxi=max(maxi,dp[i][0]);
            maxi=max(maxi,dp[i][1]);
            mp[nums[i]]=max(mp[nums[i]],dp[i][0]);
            mp[nums[i]+1]=max(mp[nums[i]+1],dp[i][1]);
            
        }
        return maxi;




    }
};