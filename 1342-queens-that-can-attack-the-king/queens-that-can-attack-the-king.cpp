class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        int x=king[0];
        int y=king[1];
        vector<vector<int>>ans;
        int n=queens.size();
        set<vector<int>>st;
        for(int i=0;i<n;i++){
            st.insert(queens[i]);
        }
        for(int i=0;i<8;i++){
            int dx=dir[i][0];
            int dy=dir[i][1];
            int nx=x+dx;
            int ny=y+dy;
            
            while(nx<8&&ny<8&&nx>-1&&ny>-1){
                if(st.find({nx,ny})!=st.end()){
                    ans.push_back({nx,ny});
                    break;
                }
                ny+=dy;
                nx+=dx;
            }
        }
        return ans;
    }
};