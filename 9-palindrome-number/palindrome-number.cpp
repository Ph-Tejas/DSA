class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else if(x<10){
            return true;
        }
        else{
            string s=to_string(x);
            int n=s.size();
            for(int i=0;i<n/2;i++){
                if(s[i]!=s[n-i-1]){
                    return false;
                }
            }
            return true;
        }
    }
};