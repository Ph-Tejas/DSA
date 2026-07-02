class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();


        priority_queue<vector<int>>pq;

        if(grid[0][0]==1)health--;

        pq.push({health,0,0});

        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};


        

        while(!pq.empty()){

            int i=pq.top()[1];
            int j=pq.top()[2];
            int h=pq.top()[0];
            cout<<i<<" "<<j<<" "<<h<<endl;


            pq.pop();


            if(grid[i][j]==-1)continue;
            grid[i][j]=-1;

            if(i==n-1 && j==m-1)return true;

            for(int k=0;k<4;k++){
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];

                if(ni<n&&nj<m&&ni>-1&&nj>-1&&grid[ni][nj]!=-1){
                    int newh=((grid[ni][nj]==1)?h-1:h);
                    if(newh<=0)continue;
                    pq.push({newh,ni,nj});
                }
                
            }







        }
        return false;










    }
};