class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&v,vector<bool>&vis){
        if(vis[node])return;
        vis[node]=true;
        v.push_back(node);

        for(int i=0;i<adj[node].size();i++){
            if(vis[adj[node][i]])continue;
            dfs(adj[node][i],adj,v,vis);
        }

    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();


        multimap<int,int>mp;
        for(int i=0;i<n;i++){
            mp.insert({nums[i],i});
        }
        vector<vector<int>>adj(n);
        auto it=mp.begin();

        auto nxt=it;
        nxt++;
        while(nxt!=mp.end()){
            
            if((*nxt).first-(*it).first<=limit){
                adj[(*nxt).second].push_back((*it).second);
                adj[(*it).second].push_back((*nxt).second);
                
            }




            it++;
            nxt++;
        }       
        vector<bool>vis(n);
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            vector<int>v1;
            dfs(i,adj,v1,vis);
            sort(v1.begin(),v1.end());
            v.push_back(v1);

        }
        vector<vector<int>>val;
        int sz=v.size();

        for(int i=0;i<sz;i++){
            vector<int>v1;
            for(int j=0;j<v[i].size();j++){
                v1.push_back(nums[v[i][j]]);
            }
            sort(v1.begin(),v1.end());
            val.push_back(v1);
        }
        // for(int i=0;i<v.size();i++){
        //     // cout<<i<<endl;
        //     for(int j=0;j<v[i].size();j++){
                
        //         cout<<val[i][j]<<" ";


        //     }
        //     cout<<endl;
        // } 
        for(int i=0;i<sz;i++){
            for(int j=0;j<v[i].size();j++){
                nums[v[i][j]]=val[i][j];
            }
        }
        return nums;



    }
};