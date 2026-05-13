class Solution {
public:
    int maxDistinct(string s) {
        vector<int>v(26);
        int ct=0;
        for(int i=0;i<s.size();i++){
            if(v[s[i]-'a']==1)continue;
            ct++;
            v[s[i]-'a']=1;
        }
        return ct;

    }
};