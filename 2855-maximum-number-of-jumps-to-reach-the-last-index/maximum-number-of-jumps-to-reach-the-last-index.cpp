class Solution {
public:
    vector<vector<int>>adj;
    vector<int>indeg;

    void dfs(int node){
        for(auto &val:adj[node]){
            indeg[val]--;
            if(indeg[val]==0)dfs(val);
        }
    }
    
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        adj.resize(n);
        indeg.resize(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(abs(nums[j]-nums[i])<=target){
                    adj[i].push_back(j);
                    indeg[j]++;
                }
            }
        }
        vector<int>vis(n,-1);
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>v;
        for(int i=1;i<n;i++){
            if(indeg[i]==0)v.push_back(i);
        }

        for(auto &val:v){
            dfs(val);
        }
        
        while(!q.empty()){
            int node=q.front().second;
            int c=q.front().first;
            q.pop();
            vis[node]=c;


            

            for(auto &val:adj[node]){
                
                indeg[val]--;
                if(indeg[val]==0)q.push({c+1,val});
            }
        }

        return vis[n-1];
    }
};