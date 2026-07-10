class Solution {
public:
    vector<vector<int>>vis;
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        vis.resize(n,vector<int>(m));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j,0});
                }
            }
        }
        if(q.size()==n*m)return -1;
        int maxi=-1;
        while(!q.empty()){
            int i=q.front()[0];
            int j=q.front()[1];
            int s=q.front()[2];
            q.pop();
            if(vis[i][j]==1)continue;
            vis[i][j]=1;
            maxi=max(maxi,s);
            for(int it=0;it<4;it++){
                int ni=i+dir[it][0];
                int nj=j+dir[it][1];
                if(ni<n&&nj<m&&ni>=0&&nj>=0&&vis[ni][nj]==0){
                    q.push({ni,nj,s+1});
                }
            }

        }
        return maxi;



    }
};