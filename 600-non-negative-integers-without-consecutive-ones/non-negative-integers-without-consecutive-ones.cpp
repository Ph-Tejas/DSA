class Solution {
public:
    vector<vector<int>>dp;
    int findIntegers(int n) {
        dp.resize(32,vector<int>(2));
        dp[0][0]=1;
        dp[0][1]=1;
        dp[1][0]=2;
        dp[1][1]=1;
        for(int i=2;i<32;i++){
            dp[i][0]=dp[i-1][1]+dp[i-1][0];
            dp[i][1]=dp[i-1][0];
        }
        vector<int>pos;
        int ct=0;
        while(n>0){
            if(n&1){
                pos.push_back(ct);
            }
            ct++;
            n/=2;
        }
        int ans=0;
        for(int i=pos.size()-1;i>-1;i--){

            int curr=pos[i];
            ans+=dp[pos[i]][0];
            if(i!=pos.size()-1){
                if(pos[i+1]-pos[i]==1)break;
            }
            if(i==0)ans++;

        }
        return ans;

    }
};