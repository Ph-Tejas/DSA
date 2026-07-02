class Trie{
public:
    Trie* collection[26];
    bool flag=false;
    Trie(){
        memset(collection,0,sizeof(collection));
    }

};

class Solution {
public:
    int n,m;
    vector<vector<bool>>vis;

    set<string>ans;
    vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
    void dfs(Trie* tr,string &s,int &sz,int idx){
        if(idx==sz){
            tr->flag=true;  
            return; 
        }
        int ch=s[idx]-'a';
        if(tr->collection[ch]==NULL){
            tr->collection[ch]=new Trie();

        }
        dfs(tr->collection[ch],s,sz,idx+1);
    }
    void finding(Trie* tr,int i,int j,vector<vector<char>>& board,string &s){
        if(vis[i][j])return;
        vis[i][j]=true;
        int ch=board[i][j]-'a';

        s.push_back(ch+'a');

        if(tr->collection[ch]!=NULL){
            if(tr->collection[ch]->flag==true){
                ans.insert(s);

            }
            
            for(int d=0;d<4;d++){
                int ni=i+dir[d][0];
                int nj=j+dir[d][1];

                if(ni<n && nj<m && ni>-1 && nj>-1 && !vis[ni][nj]){

                    finding(tr->collection[ch],ni,nj,board,s);

                }
            }
        }
        
        
        vis[i][j]=false;
        s.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n=board.size();
        m=board[0].size();
        vis.resize(n,vector<bool>(m,false));
        Trie* tr=new Trie();
        

        for(auto &s:words){
            int sz=s.size();
            dfs(tr,s,sz,0);
                
            
        }
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                string s;
                finding(tr,i,j,board,s);

            }
        }
        vector<string>fin;
        for(auto &s:ans){
            fin.push_back(s);
        }
        return fin;
    }
};