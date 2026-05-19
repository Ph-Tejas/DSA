class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    
    int fun(int st,int &en,int vis,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(st==en && ((vis | (1<<en))+1==(1<<(n*m)))){
            return 1;
        }
        if(dp[st][vis]!=-1){
            return dp[st][vis];
        }
        int ans=0;
        int x=st/m;
        int y=st%m;
        for(int i=0;i<4;i++){
            
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            int new_st=nx*m+ny;
            if(nx<n && nx>-1 && ny<m && ny>-1 && (((vis>>(new_st))&1)==0)){
                ans+=fun(new_st,en,((vis)|(1<<st)),dp,grid);
            }


        }
        return dp[st][vis]=ans;

    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int totSq=n*m;
        dp.resize(totSq,vector<int>((1<<(totSq)),-1));
        int st,en;
        int vis=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)st=i*m+j;
                if(grid[i][j]==2){
                    
                    en=i*m+j;
                }
                if(grid[i][j]==-1){
                    for(int it=0;it<(1<<totSq);it++)dp[i*m+j][it]=0;
                    vis+=(1<<(i*m+j));
                    
                }
            }
        }
        
        return fun(st,en,vis,dp,grid);
    }
};