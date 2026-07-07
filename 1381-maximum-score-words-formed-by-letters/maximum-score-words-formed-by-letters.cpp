class Solution {
public:
    int n;
    int vis;
    int tgt;
    vector<vector<int>>dp;
    map<int,int>mp;
    int fun(int i,vector<string>& words, vector<char>& letters, vector<int>& score){
        if(i==n)return 0;
        if(dp[i][vis]!=-1)return dp[i][vis];
        int notPick=fun(i+1,words,letters,score);
        int pick=0;
        bool flag=true;
        int sum=0;
        for(int it=0;it<words[i].size();it++){
            if(mp[words[i][it]-'a']<=0){
                flag=false;
            }
            mp[words[i][it]-'a']--;
            sum+=score[words[i][it]-'a'];

        }
        if(flag){
            pick+=sum;
            vis=((1<<i)|vis);
            pick+=fun(i+1,words,letters,score);
        }
        vis=((~(1<<i))&vis);
        for(int it=0;it<words[i].size();it++){
            
            mp[words[i][it]-'a']++;

        }
        return dp[i][vis]=max(pick,notPick);




    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n=words.size();
        int sz=letters.size();
        for(int i=0;i<sz;i++){
            mp[letters[i]-'a']++;
        }
        vis=0;
        tgt=(1<<n);
        dp.resize(n,vector<int>(tgt,-1));

        
        return fun(0,words,letters,score);
    }
};