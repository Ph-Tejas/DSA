class Solution {
public:
    vector<vector<int>>dp;
    unordered_map<int,int>st;
    int fun(int ind,int foot,vector<int>& stones){
        if(ind>=stones.size())return 0;
        if(ind==stones.size()-1)return 1;
        if(dp[ind][foot]!=-1)return dp[ind][foot];
        int ans=0;

        vector<int>temp={foot-1,foot,foot+1};
        for(int it=0;it<3;it++){
            if(temp[it]==0)continue;
            if(st.find(stones[ind]+temp[it])!=st.end()){

                ans=(ans|fun(st[stones[ind]+temp[it]],temp[it],stones));
            }        
              
        }
        
        return dp[ind][foot]=ans;

    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        dp.resize(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            st.insert({stones[i],i});
        }
        if(stones[1]!=1)return false;

        return fun(1,1,stones);




    }
};