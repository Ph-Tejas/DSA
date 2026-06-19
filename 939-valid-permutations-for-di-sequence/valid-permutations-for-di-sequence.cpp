class Solution {
public:
    int mod=1e9+7;
    int n;
    vector<bool>vis;
    vector<vector<long long>>dp;
    long long fun(int i,int prev,string &s){
        if(i==n){
            return 1;
        }
        if(dp[i][prev]!=-1)return dp[i][prev];
        long long total=0;
        if(s[i]=='D'){
            for(int num=0;num<prev;num++){
                if(vis[num]){
                    vis[num]=false;
                    total+=fun(i+1,num,s);
                    total%=mod;
                    vis[num]=true;
                }
            }
        }
        else{
            for(int num=prev+1;num<=n;num++){
                if(vis[num]){
                    vis[num]=false;
                    total+=fun(i+1,num,s);
                    total%=mod;
                    vis[num]=true;
                }
            }
        }
        return dp[i][prev]=total;

    }
    int numPermsDISequence(string s) {
        n=s.size();
        vis.resize(n+1,true);
        dp.resize(n+1,vector<long long>(n+1,-1));
        
        long long ans=0;
        for(int num=0;num<=n;num++){
            vis[num]=false;
            ans+=fun(0,num,s);
            ans%=mod;
            vis[num]=true;
        }
        return ans;













    }
};