class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>matrix1(n,vector<int>(m));
        vector<vector<int>>matrix2(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix1[i][j]=matrix[i][j]-'0';

                matrix2[i][j]=matrix[i][j]-'0';
            }
        }
        int maxi=0;
        vector<vector<int>>dp=matrix1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j!=0)matrix1[i][j]=((matrix1[i][j]==0)?0:1+matrix1[i][j-1]);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j!=0)matrix2[j][i]=((matrix2[j][i]==0)?0:1+matrix2[j-1][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=0){
                    int mini=INT_MAX;
                    if(i!=0){
                        mini=min(mini,matrix2[i-1][j]);
                    }
                    else mini=0;
                    if(j!=0){
                        mini=min(mini,matrix1[i][j-1]);
                    }
                    else mini=0;

                    if(i!=0&&j!=0){
                        mini=min(dp[i-1][j-1],mini);
                    }
                    else mini=0;
                    if(i==0&&j==0){
                        maxi=1;
                        continue;
                    }
                    dp[i][j]+=mini;
                    maxi=max(maxi,dp[i][j]);

                }

            }
        }
        return maxi*maxi;

        

    }
};