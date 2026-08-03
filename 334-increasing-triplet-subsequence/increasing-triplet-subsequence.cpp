class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        long long dp[3];
        fill(dp, dp + 3, LLONG_MAX);
        for(int i=0;i<n;i++){
            int k=-1;
            for(int j=2;j>-1;j--){
                if(nums[i]<dp[j] ){
                    if(j-1>-1 && nums[i]>dp[j-1]){
                        k=j;
                    }
                    else if(j==0)k=j;
                }
            }
            
            if(k!=-1)dp[k]=nums[i];
            // cout<<dp[2]<<" ";
            if(dp[2]!=LLONG_MAX)return true;
        }
        return false;
    }
};