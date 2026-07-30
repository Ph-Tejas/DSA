class Solution {
public:
    int n,m;
    vector<vector<bool>>vis;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int dfs(int i,int j,vector<vector<int>>& grid){
        vis[i][j]=true;
        int maxi=grid[i][j];
        for(int k=0;k<4;k++){
            int ni=i+dir[k][0];
            int nj=j+dir[k][1];
            if(ni<n&&nj<m&&ni>-1&&nj>-1 && !vis[ni][nj] &&grid[ni][nj]!=0){
                maxi=max(maxi,grid[i][j]+dfs(ni,nj,grid));
            }
            
        }


        vis[i][j]=false;
        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vis.resize(n,vector<bool>(m));
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    maxi=max(maxi,dfs(i,j,grid));
                }
            }
        }
        return maxi;
    }
};