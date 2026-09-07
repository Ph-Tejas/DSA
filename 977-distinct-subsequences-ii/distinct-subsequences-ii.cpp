class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<long long>dp(n);
        dp[n-1]=1;
        for(int i=n-2;i>-1;i--){
            vector<bool>vis(26);
            long long ans=1;
            for(int j=i+1;j<n;j++){
                if(!vis[s[j]-'a']){
                    ans+=dp[j];
                    ans%=mod;
                    vis[s[j]-'a']=true;
                }
            }
            dp[i]=ans;
        }
        vector<bool>vis(26);
        long long ans=0;
        for(int i=0;i<n;i++){
            if(!vis[s[i]-'a']){
                vis[s[i]-'a']=true;
                ans+=dp[i];
                ans%=mod;
            }
        }
        return ans;

    }
};