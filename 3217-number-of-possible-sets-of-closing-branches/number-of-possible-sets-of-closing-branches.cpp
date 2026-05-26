class Solution {
public:
    int N,mx;
    bool dijkstra_in(int i,int j,int vis,vector<vector<pair<int,int>>>&adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,i});
        while(!pq.empty()){
            int node=pq.top().second;
            int dist=pq.top().first;
            pq.pop();
            if(((vis>>node)&1)==0)continue;
            vis=(vis & (~(1<<node))); 
            if(node==j && dist <= mx){
                return true;
            }
            if(node==j && dist>mx){
                return false;
            }
            for(int it=0;it<adj[node].size();it++){
                int nxt=adj[node][it].first;
                if(((vis>>nxt)&1)==0)continue;
                pq.push({dist+adj[node][it].second,nxt});

            }

        }
        return false;
    }

    bool dijkstra_out(int vis,vector<vector<pair<int,int>>>&adj){
        
        for(int i=0;i<N;i++){
            if(((vis>>i)&1)==0)continue;
            for(int j=0;j<N;j++){
                if(((vis>>j)&1)==0)continue;
                if(dijkstra_in(i,j,vis,adj)==false){
                    return false;
                }



            }
        }
        return true;
    }





    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        N=n;
        mx=maxDistance;
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        int sz=roads.size();
        for(int i=0;i<sz;i++){
            mat[roads[i][0]][roads[i][1]]=min(mat[roads[i][0]][roads[i][1]],roads[i][2]);
            mat[roads[i][1]][roads[i][0]]=min(mat[roads[i][1]][roads[i][0]],roads[i][2]);
            
        }
        vector<vector<pair<int,int>>>adj(n);
        int nodes=(1<<n)-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==INT_MAX)continue;
                adj[i].push_back({j,mat[i][j]});
                adj[j].push_back({i,mat[i][j]});
            }
        }
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            if(__builtin_popcount(i)<=1){
                ans++;
            }
            else if(dijkstra_out(i,adj)){
                ans++;
            }
        }
        return ans;



    
    
    
    
    
    
    }
};