class Solution {
public:


    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    int n,m;
    bool fun(int i,int j,vector<vector<int>>& grid){
        grid[i][j]=2;
        bool ans=true;
        for(int d=0;d<4;d++){
            int ni=i+dir[d][0];
            int nj=j+dir[d][1];
            if(ni>-1&&nj>-1&&ni<n&&nj<m){
                if(grid[ni][nj]==2 || grid[ni][nj]==1)continue;
                ans=(ans&fun(ni,nj,grid));

            }
            else{
                ans=false;
            }
        }
        return ans;

    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<i<<" "<<j<<endl;
                if(grid[i][j]==2||grid[i][j]==1)continue;
                if(fun(i,j,grid))ct++;
            }
        }
        return ct;



    }
};