class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int fun(int i,int budget,vector<int>&values,vector<vector<int>>& items,int &mini){
        if(i==n){
            return budget/items[mini][1];
        }
        if(dp[i][budget]!=-1)return dp[i][budget];
        int maxi=fun(i+1,budget,values,items,mini);
        if(budget>=items[i][1]){
            maxi=max(maxi,values[i]+fun(i+1,budget-items[i][1],values,items,mini));
        }
        return dp[i][budget]=maxi;
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        vector<int>values(n);
        dp.resize(n,vector<int>(budget+1,-1));
        int ct;
        int mini=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++){
            ct=1;
            if(mini>items[i][1]){
                mini=items[i][1];
                ind=i;
            }
            for(int j=0;j<n;j++){
                if(i==j)continue;

                if(items[j][0]%items[i][0]==0){
                    ct++;
                }
            }
            values[i]=ct;
        }
        return fun(0,budget,values,items,ind);


        
    }
};