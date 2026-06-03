class Solution {
public:
    int fun(int i,int j,int &tot,vector<vector<int>>&dp,vector<int>& slices,int pic){
        
        if(pic==tot)return 0;
        if(i>j)return INT_MIN;
        if(dp[i][pic]!=-1)return dp[i][pic];
        int not_pick=fun(i+1,j,tot,dp,slices,pic);
        int pick=slices[i]+fun(i+2,j,tot,dp,slices,pic+1);
        return dp[i][pic]=max(pick,not_pick);

        
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        int k=n/3;
        vector<vector<int>>dp1(n,vector<int>(k+1,-1));
        vector<vector<int>>dp2(n,vector<int>(k+1,-1));
        
        int ans1=fun(0,n-2,k,dp1,slices,0);
        int ans2=fun(1,n-1,k,dp2,slices,0);
        return max(ans1,ans2);
        
    }
};