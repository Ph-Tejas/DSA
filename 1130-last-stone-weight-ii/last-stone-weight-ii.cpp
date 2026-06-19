class Solution {
public:
    int n;
    int sum=0;
    int tot=0;
    vector<vector<int>>dp;
    int fun(int i,int k,vector<int>& stones){
        if(k>=sum){
            return k-(tot-k);
        }
        if(i==n){
            return 1e9;
        }
        if(dp[i][k]!=-1)return dp[i][k];
        int notpick=fun(i+1,k,stones);
        int pick=fun(i+1,k+stones[i],stones);
        return dp[i][k]=min(pick,notpick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        n=stones.size();
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        tot=sum;
        sum++;
        sum/=2;
        dp.resize(n,vector<int>(3001,-1));
        return fun(0,0,stones);
    }
};