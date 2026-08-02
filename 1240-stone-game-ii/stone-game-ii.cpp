class Solution {
public:
    int n;
    int dp[101][101];
    int fun(int i,vector<int>& piles,int m){
        if(i==n)return 0;
        // cout<<i<<" "<<m<<endl;
        if(dp[i][m]!=-1)return dp[i][m];
        int sum=0;
        int ans=INT_MIN;
        for(int it=i;it<i+(2*m) && it<n;it++ ){
            sum+=piles[it];
            ans=max(ans,sum-(fun(it+1,piles,max(m,it-i+1))));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        int a=fun(0,piles,1);
      
        return ((accumulate(piles.begin(),piles.end(),0)-a)/2)+a;




    }
};