class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            int h=0;
            for(int j=0;j<m;j++){
                h+=matrix[i][j];
                matrix[i][j]=h;                
            }
        }
        for(int i=0;i<m;i++){
            int h=0;
            for(int j=0;j<n;j++){
                h+=matrix[j][i];
                matrix[j][i]=h;                
            }
        }
        int ct=0;
        for(int I=1;I<=n;I++){
            for(int J=1;J<=m;J++){
                for(int i=I-1;i<n;i++){
                    for(int j=J-1;j<m;j++){
                        if(i-I==-1&&j-J==-1){
                            if(matrix[i][j]==target)ct++;
                        }
                        else if(j-J==-1){
                            if(matrix[i][j]-matrix[i-I][j]==target)ct++;
                        }
                        else if(i-I==-1){
                            if(matrix[i][j]-matrix[i][j-J]==target)ct++;
                        }
                        else{
                            if(matrix[i][j]-matrix[i-I][j]-matrix[i][j-J]+matrix[i-I][j-J]==target)ct++;
                        }
                    }
                }
            }

        }
        return ct;
    }
};