class Solution {
public:
    int kthDigit(long long k) {
        if(k<=9)return k;
        vector<long long>v;
        for(int i=0;i<16;i++){
            v.push_back((long long)(i+1)*((long long)pow(10,i)*9));
        }
        int n=v.size();
        vector<long long>pf(n,v[0]);
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+v[i];
        }


        int it=lower_bound(pf.begin(),pf.end(),(long long)k)-pf.begin();
        

        if(it > 0)
            k -= pf[it - 1];

        k--;

        
        
        
        
        
        
        long long curr=(long long)pow(10,it);

        
        long long num=k/(it+1) , d=k%(it+1);

        long long val=curr+num;
        long long bb=val/10; 
        if(bb%2){
            val=bb*10+(9-(val%10)); 
        }
        string res=to_string(val);
        return res[d]-'0';
       
        
        















    }
};