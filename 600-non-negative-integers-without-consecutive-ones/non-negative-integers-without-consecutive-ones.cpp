class Solution {
public:
    vector<vector<int>>dp;
    int findIntegers(int n) {
        dp.resize(32,vector<int>(2,1));
        
        int ct=0;
        if(n==1)return 2;
        if(n==0) return 1;
        if(n==3)return 3;
        if(n==2)return 3;
        if(n==4)return 4;
        vector<int>pos;
        while(n>0){
            if(n&1){
                pos.push_back(ct);
            }
            ct++;
            n/=2;
        }
        dp[1][0]=2;
        for(int i=2;i<=pos[pos.size()-1];i++){
            dp[i][0]=dp[i-1][1]+dp[i-1][0];
            dp[i][1]=dp[i-1][0];
        }
        int ans=0;
        for(int i=pos.size()-1;i>-1;i--){

            int curr=pos[i];
            ans+=dp[curr][0];
            if(i!=pos.size()-1){
                if(pos[i+1]-curr==1)break;
            }
            if(i==0)ans++;

        }
        return ans;

    }
};