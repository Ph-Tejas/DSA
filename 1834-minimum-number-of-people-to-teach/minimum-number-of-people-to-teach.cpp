class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m=languages.size();
        int sz=friendships.size();
        vector<unordered_set<int>>st(m);
        for(int i=0;i<m;i++){
            for(int j=0;j<languages[i].size();j++){
                st[i].insert(languages[i][j]);
            }
        }
        vector<vector<int>>queries;
        for(int i=0;i<sz;i++){
            int a=friendships[i][0];
            int b=friendships[i][1];
            a--;
            b--;
            bool flag=false;
        
            for(int j=1;j<=n;j++){
                if(st[a].find(j)!=st[a].end() && st[b].find(j)!=st[b].end()){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                queries.push_back({a,b});
            }


        }
        int ans=INT_MAX;
        for(int i=1;i<=n;i++){
            int ct=0;
            vector<bool>vis(m,false);
            for(auto &val:queries){
                int a=val[0];
                int b=val[1];

                int c=2;
                
                    // if(b==1 && i==1)cout<<vis[a];
                if(vis[a] || st[a].find(i)!=st[a].end()){
                    c--;

                }
                if(vis[b] || st[b].find(i)!=st[b].end()){
                    c--;

                }
                    vis[b]=true;
                    vis[a]=true;

                ct+=c;



            }
            // cout<<i<<" "<<ct<<endl;
            ans=min(ans,ct);
        }
        return ans;
        






    }
};