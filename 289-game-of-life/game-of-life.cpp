class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
        vector<vector<int>>newBoard=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ct=0;
                for(int d=0;d<8;d++){
                    int ni=dir[d][0]+i;
                    int nj=dir[d][1]+j;
                    if(ni<n&&nj>-1&&ni>-1&&nj<m){
                        ct+=(newBoard[ni][nj]==1)?1:0;
                    }
                    
                }
                if(board[i][j]==1){
                    if(ct<2||ct>3)board[i][j]=0;
                }
                else{
                    if(ct==3)board[i][j]=1;
                }

            }
        }
        
    }
};