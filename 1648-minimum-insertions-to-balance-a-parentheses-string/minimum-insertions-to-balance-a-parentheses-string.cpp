class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int ct=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')ct++;
            else{
                if(ct==0){
                    ans++;
                    ct++;
                }
                if(i+1<n && s[i+1]==')'){
                    
                    ct--;
                    i++;
                }
                else{
                    ct--;
                    ans++;
                }
            }
        }
        ans+=ct*2;
        return ans;
    }
};