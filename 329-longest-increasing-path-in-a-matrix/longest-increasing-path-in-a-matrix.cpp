class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    vector<vector<int>>dir;
    int fun(int i,int j,vector<vector<int>>& matrix){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=0;
        for(int it=0;it<4;it++){
            int dr=dir[it][0];
            int dc=dir[it][1];
            if(i+dr<n && i+dr>=0 && j+dc<m && j+dc>=0){
                int x=matrix[i+dr][j+dc];
                if(x>matrix[i][j]){
                    maxi=max(maxi,fun(i+dr,j+dc,matrix));
                }

            }   
            


        }
        return dp[i][j]=maxi+1;


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int maxi=INT_MIN;
        dir={{-1,0},{1,0},{0,-1},{0,1}};
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi=max(maxi,fun(i,j,matrix));
            }
        }
        return maxi;
    }
};