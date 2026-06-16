class Solution {
public:
    string processStr(string s) {
        string s_;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]-'a'>-1&&s[i]-'a'<26){
                s_.push_back(s[i]);
            }
            if(s[i]=='*'){
                if(!s_.empty())s_.pop_back();
            }
            if(s[i]=='#')s_+=s_;
            if(s[i]=='%')reverse(s_.begin(),s_.end());
        }
        return s_;
    }
};