class Solution {
public:
    int N;
    int mod=1e9+7;
    vector<vector<vector<long long>>>dp;
    long long fun(int i,int k,int st){
        // cout<<i<<" "<<k<<" "<<st<<endl;
        if(k==0){
            return 1;

        }

        if(i==N){
            if(st==2 && k==1)return 1;
            return 0;
        }
        if(dp[i][k][st]!=-1)return dp[i][k][st];

        int pck;
        if(st==0){
            
            pck=(fun(i+1,k,1)+fun(i+1,k,0))%mod;
            

        }
        else if(st==1){
            pck=(fun(i+1,k,2))%mod;
            
        }
        else{
            pck=(fun(i-1,k-1,0)+fun(i+1,k,2))%mod;
            
        }
        return dp[i][k][st]=pck;
    }
    int numberOfSets(int n, int k) {
        N=n;
        dp.resize(n,vector<vector<long long>>(k+1,vector<long long>(3,-1)));
        return fun(0,k,0);
    }
};