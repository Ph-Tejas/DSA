class Solution {
public:
    bool checkLo(char c){
        if(c-'a'>=0&&c-'z'<26)return true;
        return false;
    }
    int numberOfSpecialChars(string word) {
        vector<int>v(26);
        int n=word.size();
        int ct=0;
        for(int i=0;i<n;i++){
            if(checkLo(word[i]) && v[word[i]-'a']==0){
                v[word[i]-'a']=1;
            }
            
        }
        for(int i=0;i<n;i++){
            if(!checkLo(word[i]) && v[word[i]-'A']==1){
                v[word[i]-'A']=2;
                ct++;
            }
            
        }
        return ct;
    }
};