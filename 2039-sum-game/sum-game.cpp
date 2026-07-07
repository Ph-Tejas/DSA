class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int ct1=0;
        int ct2=0;
        int num1=0;
        int num2=0;

        for(int i=0;i<n/2;i++){
            if(num[i]=='?')ct1++;
            else num1+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?')ct2++;
            else num2+=num[i]-'0';
        }
        if(ct1>ct2){
            swap(ct1,ct2);
            swap(num1,num2);
        }
        else if(ct1==ct2){
            if(num1==num2)return false;
            else return true;
        }
        ct2-=ct1;
        num1-=num2;
        if(ct2&1)return true;
        if((ct2/2)*9==num1){
            return false;
        }
        return true;



    }
};