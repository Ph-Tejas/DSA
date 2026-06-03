class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int fun(int i,vector<vector<int>>& pairs,int last){
        if(i==n)return 0;
        if(dp[i][last+1001]!=-1)return dp[i][last+1001];
        int not_pick=fun(i+1,pairs,last);
        int pick=0;
        if(pairs[i][0]>last){
            pick=1+fun(i+1,pairs,pairs[i][1]);
        }
        return dp[i][last+1001]=max(pick,not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin(),pairs.end());

        dp.resize(n,vector<int>(2003,-1));
        return fun(0,pairs,-1001);



    }
};