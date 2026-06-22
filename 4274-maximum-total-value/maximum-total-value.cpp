#define ll long long
class Solution {
public:
    int mod=1e9+7;
    ll findNum(ll a,ll d,ll mid){
        if(mid>=a)return 0;
        return (((a-mid)-1)/(abs(d)))+1;
    }
    bool findIsPresent(ll a,ll d,ll n,ll mid){
        
        return (mid==a+(n*d));
    }
    ll findSum(ll a,ll d,ll num){
        return ((num*((2*a)+(num-1)*d))/2)%mod;
    }
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        int n=value.size();
        ll mini=0;
        ll maxi=1e9;
        ll mid=mini+(maxi-mini)/2;
        mid=7;
        while(maxi>=mini){
            ll M=m;
            for(int i=0;i<n;i++){
                ll a=value[i];
                ll d=decay[i];
                ll num=findNum(a,-1*d,mid);
                M-=num;





            }

            if(M>=0){
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }
            mid=mini+(maxi-mini)/2;

        
        }
        ll actual=mini;
        ll ans=0;
        ll calc=0;

        for(int i=0;i<n;i++){

            ll a=value[i];
            ll d=decay[i];
            ll num=findNum(a,-1*d,actual);
            m-=num;
            ans+=findSum(a,-1*d,num);
            ans%=mod;
            calc+=findIsPresent(a,-1*d,num,actual);
            
            
            
        }
        ll k=min(calc,(ll)m);
        ans+=(k*actual)%mod;
        ans%=mod;
        return ans;






    }
};