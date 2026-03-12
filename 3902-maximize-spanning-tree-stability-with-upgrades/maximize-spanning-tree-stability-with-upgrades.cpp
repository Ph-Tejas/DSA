class DSU{
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        rank.resize(n+1);
        for(int i=0;i<=n;i++){
            parent.push_back(i);
        }
    }
    int findUpar(int u){
        if(parent[u]==u)return u;
        return parent[u]=findUpar(parent[u]);
    }
    void connecting(int u,int v){
        int ultU=parent[u];
        int ultV=parent[v];
        if(ultU==ultV)return;
        if(rank[ultU]<rank[ultV]){
            parent[ultU]=ultV;
        }
        if(rank[ultU]>rank[ultV]){
            parent[ultV]=ultU;
        }
        if(rank[ultU]==rank[ultV]){
            parent[ultU]=ultV;
            rank[ultV]++;
        }
    }
    
};
class Solution {
public:
    
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            if(a[3]==b[3]){
                return a[2]>b[2];
            }
            return a[3]>b[3];

        });
        DSU ds1(n+1);
        for(int i=0;i<edges.size();i++){
            if(ds1.findUpar(edges[i][0])==ds1.findUpar(edges[i][1])&&edges[i][3]==1){
                return -1;

            }
            ds1.connecting(edges[i][0],edges[i][1]);

        }
        set<int>st;
        for(int i=0;i<n;i++){
            ds1.parent[i]=ds1.findUpar(i);
            st.insert(ds1.parent[i]);
            if(st.size()>1){
                return -1;
            }
        }


        

        int mini=0;
        int maxi=200001;
        int mid=mini+(maxi-mini)/2;
        while(maxi>=mini){
            DSU ds(n+1);
            int K=k;
            bool response=true;
            for(int i=0;i<edges.size();i++){
                if(edges[i][3]==1){
                    ds.connecting(edges[i][0],edges[i][1]);
                    if(edges[i][2]<mid){
                        response=false;
                        break;
                    }
                    
                    

                }
                else{
                    if(ds.findUpar(edges[i][0])==ds.findUpar(edges[i][1])){
                        continue;
                    }
                    ds.connecting(edges[i][0],edges[i][1]);
                    if(edges[i][2]<mid){
                        if(K==0){
                            response=false;
                            break;
                        }
                        if(2*edges[i][2]<mid){
                            response=false;
                            break;
                        }
                        K--;

                    }

                }


            }
            if(response){
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }

            








            mid=mini+(maxi-mini)/2;
        }
        return maxi;




    }
};