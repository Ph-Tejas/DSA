class Solution {
public:
    int mod=1e9+7;
    long long powy(long long n,long long p){
       
        long long res=1;
        while(true){
        if(p&1){
            res*=n;
            res%=mod;
            p--;
        }
        else{
            if(p==0)return res;
            n*=n;
            n%=mod;
            p/=2;

        }
        }

        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
       
        int mn=0;
        int mx=n-1;
        for(int i=0;i<n;i++){
            if(nums[mn]+nums[i]>target){
                mx=i-1;
                break;
            }
        }
        if(mx<mn)return 0;
        long long ans=0;
        while(mn<=mx){
            cout<<mn<<" "<<mx<<endl;
            ans+=powy(2,mx-mn);
            ans%=mod;
            mn++;
            if(mn==n)break;
            while(nums[mn]+nums[mx]>target){
                mx--;
                if(mn>mx)break;
            }
        }
        return ans;
    }
};