class Solution {
public:
    char processStr(string s, long long k) {
        int n=s.size();
        long long szz=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(szz!=0){
                    szz--;
                }
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
        if(k>=szz){
            return '.';
        }
        k++;
        for(int i=0;i<26;i++){
            long long sz=szz;
            long long K=k;
            char ch=i+'a';
            if(count(s.begin(),s.end(),ch)==0)continue;
            
            int it=n-1;
            bool flag=false;
            while(it>-1){
                if(s[it]=='*'){
                    sz++;
                }
                else if(s[it]=='%'){
                    
                    K=(sz-(K-1));
                    
                }
                else if(s[it]=='#'){
                    sz/=2;
                    if(K>sz){
                        K=K-(sz);
                    }
                    
                }
                else{
                    if(sz==K){
                        if(s[it]==ch){
                            return ch;
                        }
                        else {
                            flag=true;
                            break;
                        }
                    }
                    else{
                        sz--;
                    }

                }



                it--;
            }
            
            if(!flag && s[K-1]==ch){
                return ch;
            }

        }
        return 'a';
    }
};