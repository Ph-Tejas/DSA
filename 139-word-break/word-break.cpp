class Solution {
public:
    set<string>st;
    vector<int>dp;
    int n;
    bool fun(string &s,int idx){
        if(idx==n)return 1;
        if(dp[idx]!=-1)return dp[idx];

        bool ans=0;
        string str;
        for(int i=idx;i<n;i++){
            str.push_back(s[i]);
            if(st.find(str)!=st.end()){
                ans=(ans|fun(s,i+1));

            }
            if(ans==true)break;
        }
        return dp[idx]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(auto &str:wordDict){
            st.insert(str);
        }
        dp.resize(n,-1);

        return fun(s,0);


    }
};