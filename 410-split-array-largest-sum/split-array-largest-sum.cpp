class Solution {
public:
    vector<vector<int>>mat;
    vector<vector<int>>dp;
    int n;
    int fun(int ind,int k,vector<int>&nums){
        if(ind==n)return 0;

        if(dp[ind][k]!=-1)return dp[ind][k];
        int mini=INT_MAX;
        if(k==1){

            return dp[ind][k]=mat[ind][n-1];
        }
        for(int it=ind;it<n-k+1;it++){
            mini=min(mini,max(mat[ind][it],fun(it+1,k-1,nums)));
        }
        return dp[ind][k]=mini;
    }
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
        vector<int>pf(n);
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
            pf[i]=nums[i]+pf[i-1];
        }
        mat.resize(n,vector<int>(n));
        dp.resize(n,vector<int>(k+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==0){
                    mat[i][j]=pf[j];
                }
                else{
                    mat[i][j]=pf[j]-pf[i-1];
                }
            }
        }
        return fun(0,k,nums);





    }
};