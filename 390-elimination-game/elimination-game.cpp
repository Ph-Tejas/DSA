class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)return 1;
        int sz=n;
        int st=1;
        int en=n;
        bool fr=1;
        int mul=2;
        int it=0;

        while(true){
            // cout<<st<<" "<<en<<" "<<mul<<" "<<it<<" "<<sz<<endl;
            if(sz==1)return st;
            if(fr){
                int N=((en-st)/mul)+1;
                int an=st+((N-1)*mul);
                
                if(an==en){

                    en=en-pow(2,it);
                }
                st=st+pow(2,it);
            }
            else{
                int N=((st-en)/(-1*mul))+1;
                int an=en+((N-1)*(-1*mul));
                if(an==st){

                    st=st+pow(2,it);
                }
                en=en-pow(2,it);

            }
            sz/=2;
            fr=(!fr);
            mul*=2;
            it++;
            
            
        }
        return 1;
    }
};