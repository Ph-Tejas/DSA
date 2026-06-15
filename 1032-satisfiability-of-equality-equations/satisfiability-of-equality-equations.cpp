class DisjointSet{
public:
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node])return node;
        return parent[node]=findUpar(parent[node]);
    }
    void unionByrank(int u,int v){
        int ult_u=findUpar(u);
        int ult_v=findUpar(v);
        if(ult_u==ult_v)return;
        if(rank[ult_u]>rank[ult_v]){
            rank[ult_v]=rank[ult_u];
            parent[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            rank[ult_u]=rank[ult_v];
            parent[ult_u]=ult_v;
        }
        else{
            parent[ult_u]=ult_v;
            rank[ult_v]++;
            rank[ult_u]=rank[ult_v];
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        DisjointSet ds(28);
        for(auto str:equations){
            

            if(str[1]=='!')continue;
            int a=str[0]-'a';
            int b=str[3]-'a';
            ds.unionByrank(a,b);


            
        }
        for(auto str:equations){
            

            if(str[1]=='=')continue;
            int a=str[0]-'a';
            int b=str[3]-'a';
            if(ds.findUpar(a)==ds.findUpar(b))return false;;


            
        }
        return true;
        
        
    }
};