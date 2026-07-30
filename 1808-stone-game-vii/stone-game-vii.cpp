class Solution {
public:
    vector<vector<int>>sum;
    vector<vector<int>>dp;
    int fun(int i,int j,vector<int>& stones){
        if(i==j)return 0;
        if(j-i==1)return max(stones[i],stones[j]);
        if(dp[i][j]!=-1)return dp[i][j];

        return dp[i][j]=max(sum[i][j-1]-fun(i,j-1,stones),sum[i+1][j]-fun(i+1,j,stones));

    }
    int stoneGameVII(vector<int>& stones) {
        int n=stones.size();
        sum.resize(n,vector<int>(n));
        dp.resize(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int h=0;
            for(int j=i;j<n;j++){
                h+=stones[j];
                sum[i][j]=h;
            }
        }
        return fun(0,n-1,stones);


        
    }
};