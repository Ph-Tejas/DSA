class Solution {
public:
    void formLPS(string b,int m,vector<int>&lps){
        
        int len=0;
        int i=1;
        while(i<m){
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
                i++;
                
            }
            else{
                if(len==0){
                    lps[i]=0;
                    i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
    }
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        vector<int>cases={(m/n),(m/n)+1,(m/n)+2,(m/n)+3};
        string temp="";
        for(int i=0;i<cases[0];i++){
            temp+=a;
        }
        vector<int>lps(m);
        formLPS(b,m,lps);
        
        for(int ct=0;ct<4;ct++){

            int i=0;
            int j=0;
            while(i<temp.size()){
                if(b[j]==temp[i]){
                    i++;
                    j++;
                }
                if(j==m){
                    return cases[ct];
                }
                
                else if(i<temp.size()&&b[j]!=temp[i]){
                    if(j==0){
                        i++;
                    }
                    else{
                        j=lps[j-1];

                    }
                }
            }

            
            


            temp+=a;
        }
        return -1;






    }
};