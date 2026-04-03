class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
        int m=t.size();
        int i=0;
        int j=0;
        while(j<n&&i<m){
            if(s[j]==t[i])i++;
            j++;
        }
        return m-i;
    }
};