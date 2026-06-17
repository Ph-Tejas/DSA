class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long szz=0;

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(szz) szz--;
            }
            else if(s[i]=='%'){
                continue;
            }
            else if(s[i]=='#'){
                szz*=2;
            }
            else{
                szz++;
            }
        }

        if(k>=szz) return '.';

        long long K=k+1;
        long long sz=szz;

        int it=n-1;

        while(it>=0){

            if(s[it]=='*'){
                sz++;
            }
            else if(s[it]=='%'){
                K=sz-(K-1);
            }
            else if(s[it]=='#'){
                sz/=2;
                if(K>sz){
                    K-=sz;
                }
            }
            else{

                if(sz==K){
                    return s[it];
                }

                sz--;
            }

            it--;
        }

        return '.';
    }
};