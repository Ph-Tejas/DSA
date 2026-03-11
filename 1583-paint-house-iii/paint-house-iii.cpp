class Solution {
public:
    int n,m;
    vector<vector<vector<int>>>dp;
    int solve(int prev,int ind,int target,vector<int>& houses, vector<vector<int>>& cost){
        if(ind==n&&target==0){
            return 0;
        }
        
        if(target<0||ind==n){
            return 1e9;
        }
        if(dp[prev][ind][target]!=-1){
            return dp[prev][ind][target];
        }
        int ans=-1;
        if(houses[ind]!=0){
            if(houses[ind]==prev){
                ans=solve(prev,ind+1,target,houses,cost);
            }
            else{

                ans=solve(houses[ind],ind+1,target-1,houses,cost);
            }

        }
        else{
            int mini=INT_MAX;
            for(int i=0;i<m;i++){
                if(i+1==prev){
                    mini=min(mini,cost[ind][i]+solve(i+1,ind+1,target,houses,cost));
                }
                else{
                    mini=min(mini,cost[ind][i]+solve(i+1,ind+1,target-1,houses,cost));
                }
            }
            ans=mini;
        }
        return dp[prev][ind][target]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n_, int m_, int target) {
        n=n_;
        m=m_;
        dp.resize(m+1,vector<vector<int>>(n,vector<int>(target+1,-1)));
        int ans=-1;
        if(houses[0]==0){
            int mini=INT_MAX;
            for(int i=0;i<m;i++){
                mini=min(mini,cost[0][i]+solve(i+1,1,target-1,houses,cost));
            }
            ans=mini;
        }
        else{
            ans=solve(houses[0],1,target-1,houses,cost);
        }

        if(ans>=1e9)return -1;
        return ans;



    }
};