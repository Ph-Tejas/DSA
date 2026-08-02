class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int fun(int i,vector<int>& piles,int m){
        if(i==n)return 0;
        cout<<i<<" "<<m<<endl;
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
        dp.resize(n,vector<int>(n+1,-1));
        int a=fun(0,piles,1);
      
        return ((accumulate(piles.begin(),piles.end(),0)-a)/2)+a;




    }
};