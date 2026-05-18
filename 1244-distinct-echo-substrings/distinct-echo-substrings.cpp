class Solution {
public:
    long long mod=1e9+7;
    long long powy(long long a,long long b){
        long long res=1;

        while(b){
            if(b&1) res=(res*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }

        return res;
    }
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        vector<vector<long long>>rpr(n,vector<long long>(n));
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vector<int> ans;
        vector<long long>power(n);
        for(int i=0;i<n;i++){
            power[i]=powy(27,i)%mod;
        }
        
        vector<long long> invPower(n);

        for(int i=0;i<n;i++){
            power[i]=powy(27,i)%mod;
            invPower[i]=powy(power[i],mod-2)%mod;
        }
        vector<long long>cWise(n);
        for(int i=0;i<n;i++){
            cWise[i]=1+(text[i]-'a');
            if(i!=0){
                cWise[i]=((((cWise[i]%mod)*(power[i]%mod))%mod)+(cWise[i-1]%mod))%mod;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==0){
                    rpr[i][j]=cWise[j];
                }
                else rpr[i][j]=(((cWise[j]-cWise[i-1]+mod)%mod)*invPower[i])%mod;
                
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(vis[i][j])continue;
                int ln=j-i+1;

                for(int it=1;;it++){
                    if(j+(it*ln)>=n || rpr[(i+(it*ln))][j+(it*ln)]!=rpr[i][j])break;

                
                    vis[(i+(it*ln))][j+(it*ln)]=true;
                    vis[(i)][j+(it*ln)]=true;
                    if(it&1)ans.push_back(rpr[i][j+(it*ln)]);
                    
                    
                }


            }
        }
        set<int>fin;
        for(int i=0;i<ans.size();i++){
           
            fin.insert(ans[i]);
        }
        return fin.size();






    }
};
