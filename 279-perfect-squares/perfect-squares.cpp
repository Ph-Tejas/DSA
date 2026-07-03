class Solution {
public:
    vector<int>nums;
    int sz;
    vector<vector<int>>dp;
    int fun(int idx,int n){
        if(n==0)return 0;
        if(idx==sz){
            return 1e5;
        }
        if(dp[idx][n]!=-1)return dp[idx][n];
        
        int ans=min(fun(idx+1,n),
                    ((n-nums[idx]>=0)?
                        (1+min(fun(idx,n-nums[idx]),
                            fun(idx+1,n-nums[idx]))):
                                (int)1e5));
        return dp[idx][n]=ans;
        

    }
    int numSquares(int n) {
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        sz=nums.size();
        dp.resize(sz,vector<int>(n+1,-1));
        return fun(0,n);


    }
};