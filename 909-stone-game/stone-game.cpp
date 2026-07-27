class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int fun(int i,int j,vector<int>&piles){
        if(j-i==0){
            return piles[i];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=max(piles[i]+fun(i+1,j,piles),piles[j]+fun(i,j-1,piles));

    }
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        return (fun(0,n-1,piles)>0?true:false);
    }
};