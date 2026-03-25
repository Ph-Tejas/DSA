class Solution {
public:
    int fun(int n){
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 2;
        
        int mini=INT_MAX;
        // if(n%3==0){
        //     mini=min(mini,fun(n/3)+1);
        // }
        // if(n%2==0){
        //     mini=min(mini,fun(n/2)+1);
        // }
        int ct=n%3;
        int ct2=n%2;
        mini=min(mini,fun((n-ct)/3)+ct+1);
        mini=min(mini,fun((n-ct2)/2)+ct2+1);
    

        

        
        
        


        return mini;
    }
    int minDays(int n) {

        

        return fun(n);
        

    }
};