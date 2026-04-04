class Solution {
public:
    vector<vector<int>>grid;
    vector<vector<int>>dp;
    int n;
    int fun(int i,int k){
        
        
        if(k==1){
            return grid[i][n-1];
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }

        int mini=INT_MAX;
        for(int it=i;it<n-k+1;it++){
            mini=min(mini,grid[i][it]+fun(it+1,k-1));
        }
        return dp[i][k]=mini;

    }
    int palindromePartition(string s, int k) {
        n=s.size();
        grid.resize(n,vector<int>(n));
        dp.resize(n,vector<int>(k+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ct=0;
                for(int it=0;i+it<j-it;it++){
                    if(s[i+it]!=s[j-it])ct++;
                }
                grid[i][j]=ct;

            }

        }
        return fun(0,k);




    }
};