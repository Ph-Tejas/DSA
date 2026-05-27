class DSU{
public:
    vector<int> parent,rank;
    DSU(int n){
        for(int i=0;i<=n;i++){
            parent.push_back(i);
            
        }
        rank.resize(n+1);
    }
    int findUpar(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findUpar(parent[u]);
    }
    void join(int u,int v){
        int uu=findUpar(u);
        int uv=findUpar(v);

        if(uu==uv)return;
        if(rank[uu]>rank[uv]){
            parent[uv]=uu;
        }
        else if(rank[uu]<rank[uv]){
            parent[uu]=uv;
        }
        else{
            parent[uv]=uu;
            rank[uu]++;
        }
    }
};
class Solution {
public:

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        if(threshold==0){
    return vector<bool>(queries.size(), true);
}
        DSU ds(n+1);
        
        for(int i=threshold+1;i<=n;i++){
            
            for(int j=i+i;j<=n;j+=i){
                ds.join(i,j);
            }
        }
        int q=queries.size();
        vector<bool>ans(q,false);
        for(int i=0;i<q;i++){
            if(ds.findUpar(queries[i][0])==ds.findUpar(queries[i][1]))ans[i]=true;
        }
        return ans;
    }
};