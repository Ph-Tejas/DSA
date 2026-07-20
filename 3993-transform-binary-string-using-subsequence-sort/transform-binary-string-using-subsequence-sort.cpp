class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=strs.size();
        vector<int>v;
        vector<bool>ans(n);
        int CT0=0;
        int CT1=0;
        int m=s.size();
        for(int i=0;i<m;i++){
            if(s[i]=='1')CT1++;
            else if(s[i]=='0')CT0++;
        }
        for(int i=0;i<n;i++){
            int ct0=0;
            int ct1=0;
            int ctq=0;
            for(int j=0;j<m;j++){
                if(strs[i][j]=='1')ct1++;
                else if(strs[i][j]=='0')ct0++;
                
                
                

            }
            if(ct1>CT1||ct0>CT0)continue;
            int a=CT1-ct1;
            for(int j=m-1;j>-1;j--){
                if(a!=0 && strs[i][j]=='?'){
                    a--;
                    strs[i][j]='1';
                }   
                else if(a==0&& strs[i][j]=='?')strs[i][j]='0';
            }
            bool fin=false;
            int aaa=0;
            for(int j=0;j<m;j++){
            
                    
                if(strs[i][j]=='0' && s[j]=='1'){
                    aaa++;
                }
                else if(strs[i][j]=='1' && s[j]=='0'){
                    aaa--;
                    if(aaa<0)fin=true;
                }
            
                
            }
            if(!fin)ans[i]=true;


        }
        return ans;
    }
};