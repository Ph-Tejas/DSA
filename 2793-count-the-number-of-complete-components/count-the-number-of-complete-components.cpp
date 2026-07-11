class Solution {
public:
    vector<vector<int>>adj;
    vector<bool> vis;
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int sz=edges.size();
        adj.resize(n);
        vis.resize(n,true);
        for(int i=0;i<sz;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ct=0;
        for(int i=0;i<n;i++){
            
            if(vis[i]){
                bool flag=false;    
                vis[i]=false;
                int node=adj[i].size();
                set<int>st;
                for(int j=0;j<node;j++){
                    vis[adj[i][j]]=false;
                    st.insert(adj[i][j]);

                }
                st.insert(i);
                for(int j=0;j<node;j++){
                    set<int>stt=st;


                    int curr=adj[i][j];
                    if(stt.find(curr)!=stt.end()){
                        stt.erase(curr);
                        for(int k=0;k<adj[curr].size();k++){
                            if(stt.find(adj[curr][k])!=stt.end()){
                                stt.erase(adj[curr][k]);
                                vis[adj[curr][k]]=false;
                            }
                            else {
                                flag=true;

                                vis[adj[curr][k]]=false;
                            }
                        }
                        if(stt.size()!=0){
                            flag=true;
                        }
                    }
                    else flag=true;


                }

                if(!flag)ct++;
            }
            
        }
        return ct;
    }
};