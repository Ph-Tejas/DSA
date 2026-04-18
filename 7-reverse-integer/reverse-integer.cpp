
class Solution {
public:
    void reverse_(string &s){
        for(int i=0;i<s.size()/2;i++){
            swap(s[i],s[s.size()-1-i]);
        }
        
    }

    int reverse(int x) {
        if(x==0)return 0;
        if(x==INT_MIN)return 0;
        string s1=to_string(INT_MAX);
        string s2=s1;
        s2[s2.size()-1]++;
        bool flag=false;
        if(x<0)flag=true;
        x=abs(x);
        if(flag){
            string s=to_string(x);
            while(s.back()=='0')s.pop_back();
            reverse_(s);
            if(s.size()>s2.size()){
                return 0;
            }
            if(s>s2&&s.size()==s2.size()){
                return 0;

            }
            if(s==s2){
                return INT_MIN;
            }
            int a=-1*stoi(s);
            return a;


        }
        else{
            string s=to_string(x);

            while(s.back()=='0')s.pop_back();
            reverse_(s);
            if(s.size()>s1.size()){
                return 0;
            }
            if(s>s1&&s.size()==s1.size()){
                return 0;

            }
            int a=stoi(s);
            return a;

        }

    }
};