class Solution {
public:
    string convert(string s, int rows) {
        int n=s.size();
        vector<vector<char>>grid(rows,vector<char>(n,'?'));
        if(rows==1){
            return s;
        }
        int c=0;
        int r=0;
        int it=0;
        while(it<n){
            for(r;r<rows && it<n;r++,it++){
                grid[r][c]=s[it];
                
                
            }
            if(r==rows)r--;
            while(it<n){
                r--;
                c++;
                if(r==0)break;
                grid[r][c]=s[it];
                
                it++;
            }

        }
        string ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!='?'){
                    ans.push_back(grid[i][j]);
                }
            }
        }
        return ans;

    }
};