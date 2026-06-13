class Solution {
public:
    int fun(vector<vector<int>>& rowConditions,map<int,int>&v, int &k){
        int n=rowConditions.size();
        vector<int>inDegree(k+1);
        vector<bool>vis(k+1);
        
        vector<vector<int>>adj(k+1);
        for(int i=0;i<n;i++){
            adj[rowConditions[i][0]].push_back(rowConditions[i][1]);
            inDegree[rowConditions[i][1]]++;
        }
        queue<int>q;
        for(int i=1;i<=k;i++){
            if(inDegree[i]==0){
                
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            v[curr]=(v.size());
            q.pop();
            if(vis[curr])return -1;
            vis[curr]=true;
            for(int i=0;i<adj[curr].size();i++){
                if(vis[adj[curr][i]])continue;
                inDegree[adj[curr][i]]--;
                if(inDegree[adj[curr][i]]==0)q.push(adj[curr][i]);
            }
        }
        if(v.size()!=k)return -1;
        return 1;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        map<int,int>v1,v2;
        int a=fun(rowConditions,v1,k);
        if(a==-1)return {};
        int b=fun(colConditions,v2,k);
        if(b==-1)return {};
        for(auto val:v1){
            cout<<val.first<<" "<<val.second<<endl;
        }
        vector<vector<int>>ans(k,vector<int>(k));
        for(int i=1;i<=k;i++){
            ans[v1[i]][v2[i]]=i;
        }




        return ans;
        
        

        
    }
};