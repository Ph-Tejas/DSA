class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int sz=connections.size();
        vector<vector<int>>adj(n);
        set<pair<int,int>>st;
        for(int i=0;i<sz;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            st.insert({a,b});
            st.insert({b,a});
            
            
        }
        queue<pair<int,int>>q;
        q.push({0,-1});
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                int curr=adj[node][i];
                if(curr==par)continue;
                st.erase({curr,node});
                q.push({curr,node});
            }
        }
        int ans=0;
        for(auto val:st){
            cout<<val.first<<" "<<val.second<<endl;
        }
    
        for(int i=0;i<sz;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            if(st.find({a,b})!=st.end()){
                ans++;

            }
        }
        return ans;
    }
};