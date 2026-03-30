class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        vector<int>v(26);
        for(int i=0;i<n;i+=2){
            v[s1[i]-'a']++;
        }
        for(int i=0;i<n;i+=2){
            if(v[s2[i]-'a']==0)return false;
            v[s2[i]-'a']--;

        }
        for(int i=1;i<n;i+=2){
            v[s1[i]-'a']++;
        }
        for(int i=1;i<n;i+=2){
            if(v[s2[i]-'a']==0)return false;
            v[s2[i]-'a']--;

        }
        return true;
        
        

    }
};