class Solution {
public:
    vector<vector<int>>dp;
    vector<vector<int>>cost;
    
    int n;
    int fun(int i,int k,vector<int>& houses){
        if(i==n)return 0;
        if(k==0)return 1e9;
        

        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int sum=0;
        int mul=0;
        int mini=INT_MAX;
        for(int it=i;it<n-k+1;it++){
            
            
            mini=min(mini,cost[i][it]+fun(it+1,k-1,houses));
            
            
                

        }
        return dp[i][k]=mini;
    }
    int minDistance(vector<int>& houses, int k) {
        n=houses.size();
        sort(houses.begin(),houses.end());
        dp.resize(n,vector<int>(k+1,-1));
        cost.resize(n,vector<int>(n));
        vector<int>pf(n,houses[0]);
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+houses[i];
        }
        for(int i=0;i<n;i++){
            

            for(int j=i;j<n;j++){
                int mini=INT_MAX;
                int sum=0;
                for(int l=i;l<=j;l++){
                    mini=min(mini,(((l-i)*houses[l])-sum)+((pf[j]-pf[l])-((j-l)*houses[l])));
                    sum+=houses[l];
                }   
                cost[i][j]=mini;
            }
        }
        
        return fun(0,k,houses);
        

        
    }
};