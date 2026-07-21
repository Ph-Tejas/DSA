class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int>dp(n);
        map<int,int>mp;
        mp[0]=-1;
        int prev=0;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int toSearch=target-curr;
        
            if(mp.find(prev-toSearch)!=mp.end() ){
                if(i==0){
                    dp[i]=1;

                }
                
                else if(mp[prev-toSearch]>=0){
                  
                    dp[i]=max(dp[i-1],1+dp[mp[prev-toSearch]]);
                }
                else dp[i]=max(dp[i-1],1);
            }
            else {
                if(i==0)dp[i]=0;
                else dp[i]=dp[i-1];
            }
            prev+=curr;
            // cout<<prev<<" ";

            mp[prev]=i;
            cout<<dp[i]<<" ";
        }
        
        return dp[n-1];
    
    
    
    
    
    }
};