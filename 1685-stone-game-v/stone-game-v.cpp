class Solution {
public:
int dp[501][501];
int  solve(int i,int j,vector<int>& nums,int sum){
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int temp=0;
    int ans=0;

    for(int k=i;k<j;k++){
        temp+=nums[k];
        int result=0;
        if(temp*2<sum){
            result=temp+solve(i,k,nums,temp);
        }
        else if(temp*2>sum){
            result=sum-temp+solve(k+1,j,nums,sum-temp);
        }
        else {
            result=temp+max(solve(i,k,nums,temp),solve(k+1,j,nums,sum-temp));
        }
        ans=max(ans,result);


    }
    return dp[i][j]=ans;


}

    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int n=stoneValue.size();
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=stoneValue[i];
        return solve(0,n-1,stoneValue,sum);
        
    }
};