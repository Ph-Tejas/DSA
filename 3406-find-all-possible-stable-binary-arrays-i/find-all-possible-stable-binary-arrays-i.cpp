class Solution {
public:
    int limit;
    const int MOD = 1000000007;

    int solve(int z,int o,int howMuch,vector<vector<vector<int>>>&dp){
        if(howMuch<(-1*limit)||howMuch>limit)return 0;

        if(o==0&&z==0){
            return 1;
        }
        
        if(dp[z][o][howMuch+limit]!=-1){
            return dp[z][o][howMuch+limit];
        }
        
        if(howMuch==(limit)){
            if(o==0)return 0;
            return dp[z][o][howMuch+limit]=solve(z,o-1,-1,dp)%MOD;
        }
        else if(howMuch==(-1*limit)){
            if(z==0)return 0;
            return dp[z][o][howMuch+limit]=solve(z-1,o,1,dp)%MOD;
        }
        else if(z==0){
            if(howMuch<0){
                return dp[z][o][howMuch+limit]=solve(z,o-1,howMuch-1,dp)%MOD;
            }
            else{
                return dp[z][o][howMuch+limit]=solve(z,o-1,-1,dp)%MOD;
            }
        }
        else if(o==0){
            if(howMuch>0){  // FIXED
                return dp[z][o][howMuch+limit]=solve(z-1,o,howMuch+1,dp)%MOD;
            }
            else{
                return dp[z][o][howMuch+limit]=solve(z-1,o,1,dp)%MOD;
            }
        }
        
        else if(howMuch<=0&&o>0&&z>0){
            return dp[z][o][howMuch+limit]=(solve(z,o-1,howMuch-1,dp)
                    +solve(z-1,o,1,dp))%MOD;
        }
        else if(howMuch>0&&o>0&&z>0){
            return dp[z][o][howMuch+limit]=(solve(z,o-1,-1,dp)
                    +solve(z-1,o,howMuch+1,dp))%MOD;
        }

        return 0;
    }

    int numberOfStableArrays(int z, int o, int l) {
        vector<vector<vector<int>>>dp(z+1,
            vector<vector<int>>(o+1,vector<int>((2*l)+1,-1)));
        limit=l;
        return solve(z,o,0,dp);
    }
};