class Solution {
public:
    int n;
    vector<int>pf;
    vector<vector<int>>dp;
    int rec(int i, int j,vector<int>& stoneValue){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i==j)return dp[i][j]=0;

        int maxi=INT_MIN;

        for(int it=i;it<j;it++){
            int sum=0;
            int a=pf[it+1]-pf[i];
            int b=pf[j+1]-pf[i]-a;
            if(a==b){
                sum+=a;
                sum+=max(rec(i,it,stoneValue),rec(it+1,j,stoneValue));

            }
            else if(a<b){
                sum+=a;
                sum+=rec(i,it,stoneValue);
            }
            else{
                sum+=b;
                sum+=rec(it+1,j,stoneValue);
            }
            maxi=max(maxi,sum);

        }
        return dp[i][j]=maxi;
    }
    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.resize(n,vector<int>(n,-1));
        pf.resize(n+1);
        for(int i=0;i<n;i++){
            pf[i+1]=pf[i]+stoneValue[i];
        }
        return rec(0,n-1,stoneValue);
    }
};