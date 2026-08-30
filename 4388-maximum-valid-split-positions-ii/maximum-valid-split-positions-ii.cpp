class Solution {
public:
    int gcd(int a,int b){
        if(a>b)swap(a,b);
        if(b%a==0)return a;
        return gcd(b%a,a);
        
    }
    
    int solve(vector<int>&nums){
        int n=nums.size();
        vector<int>pf(n,nums[0]);
        vector<int>sf(n,nums[n-1]);
        for(int i=1;i<n;i++){

            pf[i]=gcd(nums[i],pf[i-1]);
            
            
        }
        for(int i=n-2;i>-1;i--){

            sf[i]=gcd(nums[i],sf[i+1]);
            
            
        }
        int ct=0;
        for(int i=0;i<n-1;i++){
            if(pf[i]==sf[i+1])ct++;    
        }
        return ct;
        
    }
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();


        vector<int>pf(n,nums[0]);
        vector<int>sf(n,nums[n-1]);
        for(int i=1;i<n;i++){

            pf[i]=gcd(nums[i],pf[i-1]);
            
            
            
        }
        for(int i=n-2;i>-1;i--){

            sf[i]=gcd(nums[i],sf[i+1]);
            
            
        }
        int ct=0;
        int ind1=-1;
        bool flag=true;
        int ind2=-1;
        
        for(int i=0;i<n-1;i++){
            if(pf[i]==sf[i+1]){
                
                ct++;    
            }
        }
        for(int i=0;i<n;i++){
            if(pf[i]==sf[i]){
                if(flag){
                    flag=true;
                    ind1=i;
                }
                ind2=i;
                
        
            }
        }
        int ref=ct;
        
        vector<int>v1,v2;
        
        for(int i=0;i<n;i++){
            if(i==ind1)continue;
            v1.push_back(nums[i]);
        }
        ref=max(ref,solve(v1));
        v1.clear();
        
        for(int i=0;i<n;i++){
            if(i==ind1+1)continue;
            v1.push_back(nums[i]);
        }
        ref=max(ref,solve(v1));
        v1.clear();
        
        for(int i=0;i<n;i++){
            if(i==ind1-1)continue;
            v1.push_back(nums[i]);
        }
        ref=max(ref,solve(v1));



        
        for(int i=0;i<n;i++){
            if(i==ind2)continue;
            v2.push_back(nums[i]);
        }
        ref=max(ref,solve(v2));
        v2.clear();
        for(int i=0;i<n;i++){
            if(i==ind2-1)continue;
            v2.push_back(nums[i]);
        }
        ref=max(ref,solve(v2));
        v2.clear();
        for(int i=0;i<n;i++){
            if(i==ind2+1)continue;
            v2.push_back(nums[i]);
        }
        ref=max(ref,solve(v2));
        v2.clear();
        for(int i=0;i<n;i++){
            if(i==0)continue;
            v2.push_back(nums[i]);
        }
        ref=max(ref,solve(v2));
        v2.clear();
        for(int i=0;i<n;i++){
            if(i==n-1)continue;
            v2.push_back(nums[i]);
        }
        ref=max(ref,solve(v2));
        v2.clear();
        
        return ref;
        

        
        

        
    }
};