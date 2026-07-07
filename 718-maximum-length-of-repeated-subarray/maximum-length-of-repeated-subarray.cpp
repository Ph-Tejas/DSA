class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m));
        int ans=0;
        for(int i=0;i<n;i++){

            if(nums1[i]==nums2[0]){
                dp[i][0]=1;
            }
            ans=max(ans,dp[i][0]);
        }
        for(int i=0;i<m;i++){
            if(nums1[0]==nums2[i]){
                dp[0][i]=1;
            }

            ans=max(ans,dp[0][i]);
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int maxi=0;
                if(nums1[i]==nums2[j]){
                    maxi=max(maxi,1+dp[i-1][j-1]);
                }
                dp[i][j]=maxi;

                ans=max(ans,dp[i][j]);

            }
        }
        return ans;



    }
};