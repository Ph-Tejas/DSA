class Solution {
public:
    vector<vector<int>>adj;
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        adj.resize(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(abs(nums[j]-nums[i])<=target)adj[i].push_back(j);
            }
        }
        vector<int>vis(n,1e6+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({1e6,0});
        
        while(!q.empty()){
            int node=q.top().second;
            int c=q.top().first;
            q.pop();
            
            if(vis[node]<=c)continue;
            vis[node]=c;
            

            for(auto &val:adj[node]){
                if(vis[val]<=c-1)continue;
                q.push({c-1,val});
            }
        }
        return 1e6-vis[n-1];
    }
};