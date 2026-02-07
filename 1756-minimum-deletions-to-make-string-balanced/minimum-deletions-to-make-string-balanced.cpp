class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>sf(n+1);
        for(int i=n-1;i>-1;i--){
            if(s[i]=='a')sf[i]=sf[i+1]+1;
            else sf[i]=sf[i+1];
        }
        int ans=min(n-sf[0],sf[0]);
        int ct=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                ans=min(ans,sf[i+1]+ct);

            }
            else ct++;
        }
        return ans;
    }
};