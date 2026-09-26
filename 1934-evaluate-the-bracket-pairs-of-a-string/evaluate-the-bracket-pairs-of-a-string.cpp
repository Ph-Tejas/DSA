class Solution {
public:
    string evaluate(string expression, vector<vector<string>>& knowledge) {
        int n=expression.size();
        int sz=knowledge.size();

        string ans;
        string s;
        map<string,string>mp;
        for(int i=0;i<sz;i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<n;i++){
            if(expression[i]=='('){
                i++;
                while(expression[i]!=')'){
                    s.push_back(expression[i]);
                    i++;
                }
                if(mp.find(s)!=mp.end())ans+=mp[s];
                else ans+="?";
                s.clear();

            }
            else{
                ans.push_back(expression[i]);
            }
        }
        return ans;



    }
};