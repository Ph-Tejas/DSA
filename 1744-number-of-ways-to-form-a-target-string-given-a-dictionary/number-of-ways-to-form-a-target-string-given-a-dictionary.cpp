class Solution {
public:
    vector<vector<int>>v;
    vector<vector<long long>>dp;
    int mod=1e9+7;
    int n,m,t;
    long long fun(vector<string>& words, string &target, int it1,int it2){
        if(it1==t){
            return 1LL;
        }
        if(it2==m)return 0;
        if(t-it1 > m-it2)return 0;
        if(dp[it1][it2]!=-1){
            return dp[it1][it2];
        }
        long long notPick=fun(words,target,it1,it2+1);
        long long pick=0;
        if(v[it2][(target[it1]-'a')]!=0){
            pick=(v[it2][(target[it1]-'a')]*fun(words,target,it1+1,it2+1))%mod;
        }
        return dp[it1][it2]=(pick+notPick)%mod;
    }
    int numWays(vector<string>& words, string target) {
        n=words.size();
        m=words[0].size();
        t=target.size();
        v.resize(m,vector<int>(26));
        dp.resize(t,vector<long long>(m,-1));
        for(int j=0;j<m;j++){    
            for(int i=0;i<n;i++){
                v[j][words[i][j]-'a']++;
            }
        }
        return fun(words,target,0,0);





    }
};