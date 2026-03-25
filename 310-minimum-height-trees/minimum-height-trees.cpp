class Solution {
public:
    int mini=100000;
    vector<int> freq;
    int n;
    vector<int>parent;
    vector<vector<int>>adj;
    vector<pair<pair<int,int>,int>>pr;

    





    void dfs(int node,int par){
        parent[node]=par;
        int sz=adj[node].size();
        if(sz==1&&par!=-1){
            pr[node]={{0,n},0};
            return;
        }
        int a=0,b=0;
        int c=n;

        for(int i=0;i<sz;i++){
            if(adj[node][i]==par)continue;
            dfs(adj[node][i],node);
            if(pr[adj[node][i]].first.first+1>=a){
                b=a;
                a=pr[adj[node][i]].first.first+1;
                c=adj[node][i];
            }
            else if(pr[adj[node][i]].first.first+1>b){
                b=pr[adj[node][i]].first.first+1;

            }

            

        }
        pr[node]={{a,c},b};



    }
    void dfs2(int node, int par, int upDist) {
        // The actual height of the tree if 'node' is the root
        int actualMax = max(pr[node].first.first, upDist);

        if (actualMax < mini) {
            mini = actualMax;
            freq = {node};
        } else if (actualMax == mini) {
            freq.push_back(node);
        }

        for (int child : adj[node]) {
            if (child == par) continue;

            // If this child is the one that gave 'node' its max subtree height,
            // the path going "up" for this child must use the second-best option.
            int bestPathFromParent;
            if (child == pr[node].first.second) {
                bestPathFromParent = max(upDist, pr[node].second);
            } else {
                bestPathFromParent = max(upDist, pr[node].first.first);
            }

            dfs2(child, node, bestPathFromParent + 1);
        }
    }
    vector<int> findMinHeightTrees(int n_, vector<vector<int>>& edges) {
        pr.resize(n_);
        adj.resize(n_);
        parent.resize(n_);
        n=n_;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
        }
        dfs(0,-1);
        dfs2(0,0,-1);
        return freq;
        for(int i=0;i<n;i++){
            cout<<pr[i].first.first<<" "<<pr[i].first.second<<"        "<<pr[i].second<<endl;
        }




    }

};