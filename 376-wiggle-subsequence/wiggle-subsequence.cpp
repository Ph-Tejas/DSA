class Solution {
public:
    int n;
    vector<vector<vector<int>>>dp;
    int fun(int i,int prev,int dir,vector<int>&nums){
        if(i==n)return 0;
        if(dp[i][prev][dir]!=-1)return dp[i][prev][dir];

        int ntpk=fun(i+1,prev,dir,nums);
        int pk;
        if(dir==0){
            if(prev==1001){
                pk=1+fun(i+1,nums[i],!dir,nums);
            }
            else{
                if(nums[i]<prev){
                    pk=1+fun(i+1,nums[i],!dir,nums);
                }
                else{
                    pk=ntpk;
                }
            }
        }
        else{
            if(prev==1001){
                pk=1+fun(i+1,nums[i],!dir,nums);
            }
            else{
                if(nums[i]>prev){
                    pk=1+fun(i+1,nums[i],!dir,nums);
                }
                else{
                    pk=ntpk;
                }
            }
        }
        return dp[i][prev][dir]=max(ntpk,pk);

    }
    int wiggleMaxLength(vector<int>& nums) {
        n=nums.size();
        dp.resize(n,vector<vector<int>>(1002,vector<int>(2,-1)));
        return max(fun(0,1001,0,nums),fun(0,1001,1,nums));

        
    }
};