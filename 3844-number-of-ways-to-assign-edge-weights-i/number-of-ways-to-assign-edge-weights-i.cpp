class Solution {
public:
    int mod=1e9+7;
    long long powy(long long a,long long p){
        long long res=1;
        while(true){
            if(p&1){

                res*=a;
                res%=mod;
                p--;

                
            }
            else{
                if(p==0)return res;
                a*=a;
                a%=mod;
                p/=2;
            }
        }
        return 1;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int sz=edges.size();
        int n=sz+1;
        vector<vector<int>>adj(n+1);
        for(int i=0;i<sz;i++){

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{1,-1}});
        int maxi=0;
        while(!q.empty()){
            int level=q.front().first;
            int node=q.front().second.first;
            int par=q.front().second.second;
            maxi=max(maxi,level);
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                if(adj[node][i]!=par){
                    q.push({level+1,{adj[node][i],node}});
                }
            }
        }
        return powy(2,maxi-1);



    }
};