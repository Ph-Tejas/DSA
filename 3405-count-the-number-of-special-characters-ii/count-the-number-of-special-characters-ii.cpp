class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>v(26);
        int n=word.size();
        set<char>st;
        vector<bool>high(26);
        for(int i=0;i<n;i++){
            char c=word[i];
            st.insert(c);
            if(c<='z'&&c>='a'){
            
                if(v[c-'a']==1)high[c-'a']=true;
                
            }
            else{
                
                v[c-'A']=1;
            }
        }
        int ct=0;
        for(int i=0;i<26;i++){
            if(!high[i]&&st.find(i+'a')!=st.end()&&st.find(i+'A')!=st.end())ct++;
        }
        return ct;
    }
};