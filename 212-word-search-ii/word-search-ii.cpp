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
    bool vis[13][13];

    vector<string> ans;
    const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

    void dfs(Trie* tr,string &s,int &sz,int idx){
        if(idx==sz){
            tr->flag=true;
            return;
        }

        int ch=s[idx]-'a';

        if(tr->collection[ch]==NULL)
            tr->collection[ch]=new Trie();

        dfs(tr->collection[ch],s,sz,idx+1);
    }

    void finding(Trie* tr,int i,int j,vector<vector<char>>& board,string &s){

        if(vis[i][j]) return;

        int ch=board[i][j]-'a';

        Trie* nxt=tr->collection[ch];
        if(nxt==NULL) return;

        vis[i][j]=true;
        s.push_back(board[i][j]);

        if(nxt->flag){
            ans.push_back(s);
            nxt->flag=false;
        }

        for(int d=0;d<4;d++){
            int ni=i+dir[d][0];
            int nj=j+dir[d][1];

            if(ni>=0 && ni<n && nj>=0 && nj<m){
                finding(nxt,ni,nj,board,s);
            }
        }

        s.pop_back();
        vis[i][j]=false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        n=board.size();
        m=board[0].size();

        memset(vis,false,sizeof(vis));

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

        return ans;
    }
};