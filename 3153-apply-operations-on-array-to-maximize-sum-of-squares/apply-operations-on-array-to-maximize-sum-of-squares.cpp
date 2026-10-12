class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n=nums.size();
        int mod=1e9+7;
        vector<vector<int>>bits(n,vector<int>(31));
        for(int i=0;i<n;i++){
            for(int j=0;j<31;j++){
                if((nums[i]>>j)&1){
                    bits[i][j]=1;
                }
            }

        }
        vector<int>sum(31);
        for(int i=0;i<31;i++){
            for(int j=0;j<n;j++){
                sum[i]+=bits[j][i];
            }
        }
        vector<long long>tot(n);
        for(int i=0;i<31;i++){
            for(int j=0;j<sum[i];j++){
                tot[j]+=(long long)(1<<i);
                tot[j]%=mod;
            }
        }
        long long fun=0;
        for(int i=0;i<k;i++){
            fun+=(long long)tot[i]*tot[i];
            fun%=mod;
        }
        return fun;
    }
};