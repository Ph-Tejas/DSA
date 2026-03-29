class Solution {
public:
    int mod=1e9+7;
    vector<vector<long long>> collection;
    int binPow(long long n,long long p){
        long long mul=1;
        for(int i=0;i<=61;i++){
            if((p>>i)&1){
                mul*=collection[n][i];
                mul%=mod;
            }
        }
        return mul;

    }
    int multInv(int n){
        return binPow(n,mod-2)%mod;
    }

    int countVisiblePeople(int n, int pos, int k) {
        collection.resize(n+1,vector<long long>(62,1));
        for(int i=1;i<=n;i++){
            collection[i][0] = i;
            for(int j=1;j<=61;j++){
                collection[i][j] = (collection[i][j-1] * collection[i][j-1]) % mod;
            }
        }
        long long X=pos;
        long long N_X=n-X-1;
        vector<long long>x(k+1,1);
        vector<long long>n_x(k+1,1);
        for(int i=1;i<=k;i++){
            if(i>X)break;
            x[i]=x[i-1]*(X-i+1);
            x[i]%=mod;
            x[i]*=multInv(i);
            x[i]%=mod;


        }
        for(int i=1;i<=k;i++){
            if(i>N_X)break;
            n_x[i]=n_x[i-1]*(N_X-i+1);
            n_x[i]%=mod;
            n_x[i]*=multInv(i);
            n_x[i]%=mod;


        }
        long long ans=0;
        if(pos==0){
            return (n_x[k]*2)%mod;
        }
        if(pos==n-1){
            return (x[k]*2)%mod;
        }
        else{
            for(int i=0;i<=k;i++){
                if(k-i>N_X)continue;
                if(i>X)continue;
                ans+=((x[i]*n_x[k-i])%mod);
                ans%=mod;
            }
        }
        return (ans*2)%mod;
        

    }
};