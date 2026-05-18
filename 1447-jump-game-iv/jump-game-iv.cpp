class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);

        }
        vector<bool>vis(n,false);
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=true;
        while(!q.empty()){
            int ct=q.front().second;
            int node=q.front().first;
            q.pop();
            if(node==n-1)return ct;

            if(node+1<n && vis[node+1]==false){
                
                q.push({node+1,ct+1});
                vis[node+1]=true;
            }
            if(node-1>-1 && vis[node-1]==false){
                q.push({node-1,ct+1});
                vis[node-1]=true;
            }
            for(auto &val:mp[arr[node]]){
                if(val==node)continue;
                if(vis[val])continue;
                vis[val]=true;
                q.push({val,ct+1});

            }
            mp.erase(arr[node]);
        
        }
        return -1;

        
    }
};