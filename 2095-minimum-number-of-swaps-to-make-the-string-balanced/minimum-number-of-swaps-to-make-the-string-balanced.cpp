class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        int ct=0;
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                if(ct==0){
                    ct++;
                }
                else ct--;
            }
            else{
                ct++;
            }
        }
        return ct/2;
    }
};