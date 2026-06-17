class Solution {
public:
    int integerBreak(int n) {
        int ct=n/3;
        int rem=n%3;
        if(n==2)return 1;
        if(n==3)return 2;
        if(rem==0){
            return pow(3,ct);
        }
        if(rem==1){
            return pow(3,ct-1)*4;
        }
        if(rem==2){
            return pow(3,ct)*2;
        }
        return 1;



    }
};