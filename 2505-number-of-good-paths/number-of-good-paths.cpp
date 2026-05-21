class DSU{
public:
    vector<vector<int>> parent;
    vector<int>rank;
    int ans;
    DSU(int n){
        ans=0;
        for(int i=0;i<n+1;i++){
            parent.push_back({i,-1,0});
        }
        rank.resize(n+1);

    }

    int findUpar(int u){
        if(u==parent[u][0]){
            return u;

        }
        return parent[u][0]=findUpar(parent[u][0]);

    }
    void join(int u,int v,int val,int ct){
    int ru = findUpar(u);
    int rv = findUpar(v);
    if(ru == rv){
        // same component, only new current-value nodes from this edge may matter
        int old = (parent[ru][1] == val ? parent[ru][2] : 0);
        if(old > 1) ans -= 1LL * old * (old - 1) / 2;
        old += ct;
        parent[ru][1] = val;
        parent[ru][2] = old;
        if(old > 1) ans += 1LL * old * (old - 1) / 2;
        return;
    }

    int cntU = (parent[ru][1] == val ? parent[ru][2] : 0);
    int cntV = (parent[rv][1] == val ? parent[rv][2] : 0);

    if(cntU > 1) ans -= 1LL * cntU * (cntU - 1) / 2;
    if(cntV > 1) ans -= 1LL * cntV * (cntV - 1) / 2;

    int newCnt = cntU + cntV + ct;

    if(rank[ru] < rank[rv]){
        parent[ru][0] = rv;
        parent[rv][1] = val;
        parent[rv][2] = newCnt;
    }
    else if(rank[ru] > rank[rv]){
        parent[rv][0] = ru;
        parent[ru][1] = val;
        parent[ru][2] = newCnt;
    }
    else{
        parent[ru][0] = rv;
        parent[rv][1] = val;
        parent[rv][2] = newCnt;
        rank[rv]++;
    }

    if(newCnt > 1) ans += 1LL * newCnt * (newCnt - 1) / 2;
}




};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        int n=vals.size();
        int sz=edges.size();

        vector<bool>vis(n,false);
        int maxi=*max_element(vals.begin(),vals.end())+1;
        vector<vector<vector<int>>>mp(maxi);
        for(int i=0;i<sz;i++){
            int e1=edges[i][0];
            int e2=edges[i][1];
            cout<<max(vals[e1],vals[e2])<<" ";
            mp[max(vals[e1],vals[e2])].push_back({e1,e2});

        }

        DSU ds(n+1);
        for(int i=0;i<maxi;i++){
            if(mp[i].size()==0)continue;
            for(int j=0;j<mp[i].size();j++){
                int ct=0;
                int e1=mp[i][j][0];
                int e2=mp[i][j][1];
                if(vals[e1]==i && vis[e1]==false){
                    vis[e1]=true;
                    ct++;
                }
                if(vals[e2]==i && vis[e2]==false){
                    vis[e2]=true;
                    ct++;
                }
                ds.join(e1,e2,i,ct);
                
            }

        }








        return ds.ans+n;
        
    }
};