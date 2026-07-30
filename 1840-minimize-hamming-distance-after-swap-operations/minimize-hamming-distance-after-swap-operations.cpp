class DSU{
public:
    vector<int>parents;
    vector<int>rank;
    DSU(int n){
        for(int i=0;i<n;i++){
            parents.push_back(i);
            rank.push_back(0);
        }

        
    }

    int findUpar(int a){
        if(a==parents[a])return a;
        return parents[a]=findUpar(parents[a]);
    }

    void join(int u,int v){
        int ult_u=findUpar(u);
        int ult_v=findUpar(v);
        if(ult_u==ult_v)return;

        if(rank[ult_u]>rank[ult_v]){
            parents[ult_v]=ult_u;
        }
        else if(rank[ult_u]<rank[ult_v]){
            parents[ult_u]=ult_v;
        }
        else{
            parents[ult_u]=ult_v;
            rank[ult_v]++;
        }


        
    }

    
};

class Solution {
public:
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        DSU ds(n+1);
        int sz=allowedSwaps.size();
        for(int i=0;i<sz;i++){
            ds.join(allowedSwaps[i][0],allowedSwaps[i][1]);
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[ds.findUpar(i)].push_back(i);
        }

        int ans=0;
        for(auto &val:mp){
            unordered_map<int,int>mpp;
            int sz=val.second.size();
            for(auto &ind:val.second){
                mpp[source[ind]]++;
            }
            for(auto &ind:val.second){
                if(mpp[target[ind]]>0){
                    mpp[target[ind]]--;
                    sz--;

                }
            }
            ans+=sz;
            
        }
        return ans;

        
    }
};