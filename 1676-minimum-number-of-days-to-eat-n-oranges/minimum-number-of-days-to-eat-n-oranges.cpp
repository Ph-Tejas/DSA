class Solution {
public:
    map<int,int>mp;
    int fun(int n){

        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 2;
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        
        int mini=INT_MAX;
        int ct=n%3;
        int ct2=n%2;
        mini=min(mini,fun((n-ct)/3)+ct+1);
        mini=min(mini,fun((n-ct2)/2)+ct2+1);
    

        

        
        
        


        return mp[n]=mini;
    }
    int minDays(int n) {

        

        return fun(n);
        

    }
};