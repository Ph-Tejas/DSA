class Solution {
public:
    int gcd(int a,int b){
        if(a<b){
            swap(a,b);
        }
        if(a%b==0)return b;
        return gcd(b,(a%b));

    }

    vector<vector<int>>gcds;
    vector<vector<vector<int>>>dp;
    int n;
    int mod=1e9+7;
    long long fun(int i,int gcd1,int gcd2,vector<int>&nums){
        if(i==n){

            if(gcd1==gcd2 && gcd1!=0)return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];
        int curr=nums[i];

        long long ans=0;

        if(gcd1==0){
            ans+=fun(i+1,curr,gcd2,nums);
            ans%=mod;
        }
        else{
            ans+=fun(i+1,gcds[curr][gcd1],gcd2,nums);
            ans%=mod;
        }    
        if(gcd2==0){
            ans+=fun(i+1,gcd1,curr,nums);
            ans%=mod;
        }
        else{
            ans+=fun(i+1,gcd1,gcds[curr][gcd2],nums);
            ans%=mod;
        }
        ans+=fun(i+1,gcd1,gcd2,nums);
        ans%=mod;
        return dp[i][gcd1][gcd2]=ans;


    }
    int subsequencePairCount(vector<int>& nums) {
        n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        dp.resize(n,vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
        gcds.resize(maxi+1,vector<int>(maxi+1));
        for(int i=1;i<=maxi;i++){
            for(int j=1;j<=maxi;j++){
                gcds[i][j]=gcd(i,j);
            }
        }

        return fun(0,0,0,nums);


    }
};