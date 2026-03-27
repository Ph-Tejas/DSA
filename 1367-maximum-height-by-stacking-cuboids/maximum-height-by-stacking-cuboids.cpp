class Solution {
public:
    vector<vector<int>>allPerm;
    void createPerm(map<int,int>&mp,vector<int>temp){
        if(temp.size()==3){
            allPerm.push_back(temp);
            return;
        }
        for(auto &val:mp){
            if(val.second==0)continue;
            temp.push_back(val.first);
            val.second--;
            createPerm(mp,temp);
            val.second++;
            temp.pop_back();
        }
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(int i=0;i<n;i++){
            map<int,int>mp;
            for(int j=0;j<3;j++){
                mp[cuboids[i][j]]++;
            }
            createPerm(mp,{});



        }
        sort(allPerm.begin(),allPerm.end());
        int sz=allPerm.size();
        vector<int>dp(sz);
        int ans=INT_MIN;
        for(int i=0;i<sz;i++){
            int maxi=INT_MIN;
            for(int j=0;j<=i;j++){
                if(i==j){
                    maxi=max(maxi,allPerm[i][0]);
                    
                }
                else{
                    if(allPerm[i][0]>=allPerm[j][0]&&allPerm[i][1]>=allPerm[j][1]&&allPerm[i][2]>=allPerm[j][2]){
                        maxi=max(maxi,dp[j]+allPerm[i][0]);
                    }
                }
            }
            dp[i]=maxi;
            ans=max(ans,maxi);

        }
        return ans;
    }
};