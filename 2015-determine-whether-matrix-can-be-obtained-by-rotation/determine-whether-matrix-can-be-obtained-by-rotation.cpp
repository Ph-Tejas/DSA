class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        bool a=true;
        int ct=0;
        for(int i=0;i<n;i++){
            if(!a)break;
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[i][j]){
                    a=false;
                    ct++;
                    break;
                }
            }
        }
        a=true;

        for(int i=0;i<n;i++){
            if(!a)break;
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[j][n-1-i]){
                    a=false;
                    ct++;
                    break;
                }
            }
        }
        a=true;
        for(int i=0;i<n;i++){
            if(!a)break;
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[n-1-i][n-1-j]){
                    a=false;
                    ct++;
                    break;
                }
            }
        }
        a=true;
        for(int i=0;i<n;i++){
            if(!a)break;
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[n-1-j][i]){
                    a=false;
                    ct++;
                    break;
                }
            }
        }
        if(4-ct)return true;
        return false;
        

    }    
};