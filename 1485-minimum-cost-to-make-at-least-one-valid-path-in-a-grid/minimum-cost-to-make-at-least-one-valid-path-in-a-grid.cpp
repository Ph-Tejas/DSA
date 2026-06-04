class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<pair<int,int>>dir={{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        
        while(!pq.empty()){
            int cost=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(vis[i][j])continue;
            vis[i][j]=true;
            int curr=grid[i][j];
            if(i==n-1 && j==m-1)return cost;

            for(int d=1;d<=4;d++){
                int ni=i+dir[d].first;
                int nj=j+dir[d].second;
                if(ni>-1 && ni<n && nj>-1 && nj<m){
                    if(vis[ni][nj])continue;
                    
                    pq.push({(d==curr)?cost:cost+1,{ni,nj}});
                }

            }




        }
        return -1;



















    }
};