class Solution {
public:
    int n;
    int dp[100001][2][3];
    int fun(int i,int used,int prev,vector<int>&arr){

        if(i==n)return 0;
        if(dp[i][used][prev]!=-1)return dp[i][used][prev];
        int ans=0;
        if(prev==0){
            ans=max({fun(i+1,0,0,arr),fun(i+1,0,1,arr),0});
        }
        else if(prev==1){
            ans=arr[i]+max(fun(i+1,used,2,arr),0);
        }
        else{
            if(used){
                ans=max(arr[i]+fun(i+1,1,2,arr),0);
            }
            else{
                ans=max({arr[i]+fun(i+1,0,2,arr),fun(i+1,1,1,arr),0});
            }
        }
        return dp[i][used][prev]=ans;
    }
    int maximumSum(vector<int>& arr) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        int ans=max(fun(0,0,0,arr),fun(0,0,1,arr));
        return ((ans==0)?(*max_element(arr.begin(),arr.end())):ans);
    }
};