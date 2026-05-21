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
        int ult_u=findUpar(u);
        int ult_v=findUpar(v);

        

        int cnt_u=(parent[ult_u][1]==val ? parent[ult_u][2] : 0);
        int cnt_v=(parent[ult_v][1]==val ? parent[ult_v][2] : 0);

        if(cnt_u>1){
            ans-=((cnt_u)*(cnt_u-1))/2;
        }

        if(cnt_v>1){
            ans-=((cnt_v)*(cnt_v-1))/2;
        }

        int newCnt=cnt_u+cnt_v+ct;

        if(rank[ult_u]<rank[ult_v]){
            parent[ult_u][0]=ult_v;
            parent[ult_v][1]=val;
            parent[ult_v][2]=newCnt;
        }

        else if(rank[ult_u]>rank[ult_v]){
            parent[ult_v][0]=ult_u;
            parent[ult_u][1]=val;
            parent[ult_u][2]=newCnt;
        }

        else{
            parent[ult_u][0]=ult_v;
            parent[ult_v][1]=val;
            parent[ult_v][2]=newCnt;
            rank[ult_v]++;
        }

        if(newCnt>1){
            ans+=((newCnt)*(newCnt-1))/2;
        }
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