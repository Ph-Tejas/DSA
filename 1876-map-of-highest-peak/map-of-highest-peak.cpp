class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();


        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j])q.push({{i,j},0});
            }
        }
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int h=q.front().second;
            int i=q.front().first.first;
            int j=q.front().first.second;
            
            q.pop();    
            if(vis[i][j]!=-1)continue;
            vis[i][j]=h;

            for(int c=0;c<4;c++){
                int ni=dir[c][0]+i;
                int nj=dir[c][1]+j;
                if(ni>=0 && nj>=0 && ni<n &&nj<m && vis[ni][nj]==-1){
                    q.push({{ni,nj},h+1});
                }
                
            }











        }
        return vis;





    }
};