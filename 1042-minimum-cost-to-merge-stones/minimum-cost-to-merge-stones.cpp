class Solution {
public:
    int n;
    vector<int>pf;
    vector<vector<int>>dp;
    int fun(vector<int>& stones, int &k,int i,int j){
        
        if(i>=j)return 0;
        
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        for(int it=i;it<j;it+=k-1){

            
            mini=min(mini,fun(stones,k,i,it)+fun(stones,k,it+1,j));
        }
        if((j-i)%(k-1)==0)mini+=pf[j+1]-pf[i];
        return dp[i][j]=mini;

    }
    int mergeStones(vector<int>& stones, int k) {
        n=stones.size();

        if((n-1)%(k-1))return -1;
        if(n==1)return 0;
        pf.resize(n+1,0);
        for(int i=0;i<n;i++){
            pf[i+1]=pf[i]+stones[i];
        }
        dp.resize(n,vector<int>(n,-1));
        return fun(stones,k,0,n-1);
    
    }
};