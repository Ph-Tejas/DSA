
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=-1;
        int st=-1;
        int en=-1;
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(maxi<dp[i][i]){
                maxi=dp[i][i];
                st=i;
                en=i;
            }
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])dp[i][i+1]=2;
            if(maxi<dp[i][i+1]){
                maxi=dp[i][i+1];
                st=i;
                en=i+1;
            }
        }
        
        for(int diff=2;diff<n;diff++){
            for(int i=0;i<n-diff;i++){
                if(s[i]==s[i+diff]){
                    if(dp[i+1][i+diff-1]!=0){
                        dp[i][i+diff]=2+dp[i+1][i+diff-1];
                    }
                    if(maxi<dp[i][i+diff]){
                        maxi=dp[i][i+diff];
                        st=i;
                        en=i+diff;
                    }
                }
            }
        }
        return s.substr(st,en-st+1);

    }
};