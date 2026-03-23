class Solution {
public:
    vector<string>v;
    map<string,int>mp;
    
    void maker(string s,vector<int>vis){
        if(s.size()==6){
            mp[s]=v.size();
            v.push_back(s);
            return;
        }
        for(int i=1;i<=6;i++){
            if(vis[i]==1)continue;
            vis[i]=1;
            maker(s+to_string(i),vis);
            vis[i]=0;
        }
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        
        maker("",{0,0,0,0,0,0,0});
        vector<vector<int>>adj(720);
        for(int i=0;i<720;i++){
            int location=0;
            string str1=v[i];
            for(int j=0;j<6;j++){
                if(v[i][j]=='6'){
                    location=j;
                    break;
                }
            }
            if(location-1>-1&&location!=3){
                swap(str1[location],str1[location-1]);
                adj[mp[v[i]]].push_back(mp[str1]);
                swap(str1[location],str1[location-1]);
            }
            if(location+1<6&&location!=2){
                swap(str1[location],str1[location+1]);
                adj[mp[v[i]]].push_back(mp[str1]);
                swap(str1[location],str1[location+1]);
            }
            if(location-3>-1){
                swap(str1[location],str1[location-3]);
                adj[mp[v[i]]].push_back(mp[str1]);
                swap(str1[location],str1[location-3]);
            }
            if(location+3<6){
                swap(str1[location],str1[location+3]);
                adj[mp[v[i]]].push_back(mp[str1]);
                swap(str1[location],str1[location+3]);
            }
            
        }
        string target="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]==0)target+="6";
                else target+=to_string(board[i][j]);
            }
        }
        vector<int>viss(720);
        int tgt_loc=mp[target];
        queue<pair<int,int>>q;
        q.push({tgt_loc,0});
        viss[tgt_loc]=1;
        while(!q.empty()){
            int new_lock=q.front().first;
            int level=q.front().second;
            q.pop();
            if(new_lock==mp["123456"])return level;
            
            for(int i=0;i<adj[new_lock].size();i++){
                if(viss[adj[new_lock][i]]==1)continue;
                viss[adj[new_lock][i]]=1;
                q.push({adj[new_lock][i],level+1});

            }
        }
        return -1;



    }
};