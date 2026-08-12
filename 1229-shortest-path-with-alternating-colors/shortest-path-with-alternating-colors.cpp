class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int r=redEdges.size();
        int b=blueEdges.size();


        vector<vector<vector<int>>>adj(n);
        for(int i=0;i<r;i++){
            adj[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        for(int i=0;i<b;i++){
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }

        vector<int>ans(n,INT_MAX);

        vector<vector<int>>dist(n,vector<int>(2,INT_MAX));

        queue<vector<int>>q;
        q.push({0,0,0});
        q.push({0,0,1});

        while(!q.empty()){
            int node=q.front()[0];
            int lvl=q.front()[1];
            int cl=q.front()[2];
            q.pop();


            if(dist[node][cl]<=lvl)continue;
            dist[node][cl]=lvl;
            ans[node]=min(ans[node],lvl);
            for(int i=0;i<adj[node].size();i++){
                int nxtCl=adj[node][i][1];
                int nxt=adj[node][i][0];
                if(nxtCl==!cl){
                    
                    if(dist[nxt][nxtCl]<=lvl+1)continue;
                    q.push({nxt,lvl+1,nxtCl});

                }
            }




        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        return ans;
        

        


    }
};