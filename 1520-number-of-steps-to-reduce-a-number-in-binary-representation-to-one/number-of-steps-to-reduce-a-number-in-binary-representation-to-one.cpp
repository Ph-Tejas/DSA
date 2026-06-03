class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int ct=0;
        while(s.size()!=1){
            if(s.back()=='0'){
                ct++;
                s.pop_back();
                n--;
            }
            else{
                bool flag=false;
                for(int i=n-1;i>-1;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        flag=true;
                        ct++;
                        break;
                    }
                    else s[i]='0';
                }
                if(!flag){
                    s.insert(s.begin(),'1');
                    ct++;
                    n++;
                }
            }
        }
        return ct;
    }
};