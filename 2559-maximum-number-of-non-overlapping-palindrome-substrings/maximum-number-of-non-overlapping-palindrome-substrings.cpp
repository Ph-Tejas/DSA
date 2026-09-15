class Solution {

public:
    long long mod=1e9+7;
    int n;
    vector<long long>pow31;
    vector<long long>powinv31;
    vector<long long>pf;
    vector<long long>sf;
    bool isPalindrome(int i,int j){
        long long h1,h2;
        if(i==0){
            h1=pf[j];
        }
        else{
            h1=(((pf[j]-pf[i-1]+mod)%mod)*powinv31[i])%mod;
        }

        if(j==n-1){
            h2=sf[i];
        }
        else{
            h2=(((sf[i]-sf[j+1]+mod)%mod)*powinv31[n-1-j])%mod;
        }
        h1%=mod;
        h2%=mod;
        if(i==0 && j==4)cout<<h1<<" "<<h2<<endl;
        return (h1==h2);
    }
    long long powy(long long n,long long r){
        long long res=1;
        while(true){
            if(r&1){
                res*=n;
                res%=mod;
                r-=1;
            }
            else{
                if(r==0)return res%mod;
                n*=n;
                n%=mod;
                r/=2;
            }
        }
        return res;
    }
    long long invPow(int n){
        return powy(n,mod-2);
    }
    int maxPalindromes(string s, int k) {
        n=s.size();
        if(k==1)return n;
        long long l=1;

        pow31.resize(n);
        powinv31.resize(n);

        
        for(int i=0;i<n;i++){
            pow31[i]=powy(31,i);
            pow31[i]%=mod;
            powinv31[i]=invPow(pow31[i]);
        }

        pf.resize(n,((s[0]-'a')+1));
        sf.resize(n,((s[n-1]-'a')+1));
        

        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+(((s[i]-'a')+1)*pow31[l])%mod;
            pf[i]%=mod;
            
            l++;
        }
        l=1;

        for(int i=n-2;i>-1;i--){
            sf[i]=sf[i+1]+(((s[i]-'a')+1)*pow31[l])%mod;
            sf[i]%=mod;
            l++;
        }

        vector<vector<pair<int,int>>>endPoint(n);
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                
                if(isPalindrome(i,j)){
                    
                    endPoint[i].push_back({j-i+1,j});
                }

            }
            
        }
        // for(int i=0;i<n;i++){
        //     cout<<powinv31[i]<<" ";
        //     // cout<<i<<endl;
        //     // for(int j=0;j<endPoint[i].size();j++){
        //     //     cout<<endPoint[i][j].second<<" ";
        //     // }
        //     // cout<<endl;
        // }
        

        vector<int>dp(n+1,0);

        for(int i=n-2;i>-1;i--){
            int ans=dp[i+1];

            auto it=lower_bound(endPoint[i].begin(),endPoint[i].end(),make_pair(k,-1));

            if(it==endPoint[i].end()){
                dp[i]=ans;
                
            }   
            else{
                dp[i]=max(ans,1+dp[((*it).second)+1]);
            }         
        }
        
        return dp[0];







    }
};