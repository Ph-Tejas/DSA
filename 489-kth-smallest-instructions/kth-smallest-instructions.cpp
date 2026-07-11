class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    void dfs(string &s,int i,int j,int k){
        if(i==n){
            while(j<m){
                s.push_back('H');
                j++;
            }
            return;
        }
        else if(j==m){
            while(i<n){
                s.push_back('V');
                i++;
            }
            return;
        }
        if(dp[i][j+1]<k){
            s.push_back('V');
            dfs(s,i+1,j,k-dp[i][j+1]);

        }
        else{
            s.push_back('H');
            dfs(s,i,j+1,k);

        }
        
        







    }

    string kthSmallestPath(vector<int>& destination, int k) {
        
        n=destination[0];
        m=destination[1];

        dp.resize(n+1,vector<int>(m+1));
        
        for(int i=0;i<=n;i++){
            dp[i][m]=1;
        }
        
        for(int i=0;i<=m;i++){
            dp[n][i]=1;
        }
        

        for(int i=n-1;i>-1;i--){
            for(int j=m-1;j>-1;j--){
                dp[i][j]=dp[i][j+1]+dp[i+1][j];
            }
        }
        int now=0;
        string s;
        dfs(s,0,0,k);

        return s;








        
    }
};