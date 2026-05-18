class Solution {
public:
    set<string>st;
    int n;
    int sz;
    bool letsCheck(int ind,string &s,vector<int>&dp){
        if(ind==sz){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        string str;
        bool ans=false;
        for(int i=ind;i<sz;i++){
            str.push_back(s[i]);
            if(str==s)break;
            if(st.find(str)!=st.end()){
                
                ans=(ans||letsCheck(i+1,s,dp));
                if(ans)break;
            }
            
        }
        return dp[ind]=((ans==true)?1:0);

    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        n=words.size();
        for(int i=0;i<n;i++){
            st.insert(words[i]);
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            sz=words[i].size();
            vector<int>dp(sz,-1);
            if(letsCheck(0,words[i],dp)){
                ans.push_back(words[i]);

            }
        }
        return ans;
    }
};