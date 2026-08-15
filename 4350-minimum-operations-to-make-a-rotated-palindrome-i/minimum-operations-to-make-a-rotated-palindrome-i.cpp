class Solution {
public:
    int calc(string &s){
        int n=s.size();
        int ct=0;
        for(int i=0;i<n/2;i++){
            int a=s[i]-'a';
            int b=s[n-1-i]-'a';
            if(a>b){
                swap(b,a);
            }
            int mini=min(b-a,((a+26)-b));
            ct+=mini;
        }
        return ct;

    }
    void leftShift(string &s){
        char ch=s[0];
        s.erase(s.begin());
        s.push_back(ch);
    }
    int minOperations(string s) {
        int n=s.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){

            mini=min(mini,i+calc(s));
            leftShift(s);
        }
        return mini;



    }
};