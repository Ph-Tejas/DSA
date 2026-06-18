class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
            
        }   
        for(int i=2;i<=n;i++){
            
            for(int j=0;j<n-i+1;j++){
                dp[j][j+i-1]=max(nums[i+j-1]-dp[j][j+i-2],nums[j]-dp[j+1][j+i-1]);
            }
        }
        
        return (dp[0][n-1]>=0)?1:0;
    }
};