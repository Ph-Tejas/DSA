class Solution {
public:
    set<string>st;
    vector<int>dp;
    vector<vector<string>>ans;
    bool rec(int i,string &s){
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        int imp=0;

        for(int it=i;it<s.size();it++){
            temp+=s[it];
            if(st.find(temp)!=st.end()){
                imp=imp|rec(it+1,s);
            }
        }
        return dp[i]=imp;

    }
    void fun(int i,string &s,vector<string>vs){
        string temp="";
        for(int it=i;it<s.size();it++){
            temp+=s[it];
            if(st.find(temp)!=st.end()){
                if(it+1==s.size()){
                    vs.push_back(temp);
                    ans.push_back(vs);
                    return;
                }
                if(dp[it+1]==1){
                    vs.push_back(temp);
                    fun(it+1,s,vs);
                    vs.pop_back();
                }
            }

        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
        }
        dp.resize(s.size(),-1);
        vector<string>vs;
        rec(0,s);
        fun(0,s,vs);
        vector<string>final;
        for(int i=0;i<ans.size();i++){
            string temp="";
            for(int j=0;j<ans[i].size();j++){
                temp+=ans[i][j];
                temp+=" ";
            }
            temp.pop_back();
            final.push_back(temp);
        }
        return final;





    }
};