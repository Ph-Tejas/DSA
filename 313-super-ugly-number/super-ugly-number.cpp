class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int sz=primes.size();

        vector<int>v={1};
        vector<int>ptrs(sz);
        
        if(n==1)return 1;
        n-=1;
        while(n--){
            long long mini=LLONG_MAX;
            int ind=-1;
            for(int i=0;i<sz;i++){
                if(mini>(long long)v[ptrs[i]]*primes[i]){
                    mini=(long long)v[ptrs[i]]*primes[i];
                    ind=i;
                }
            
            }
            ptrs[ind]++;
            if(mini==v.back()){
                n++;
                continue;
            }   
            v.push_back(mini);

        }
        return v.back();




    }
};