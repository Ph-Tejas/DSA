class Solution {
public:
    vector<vector<int>>grid;
    int mod=1e9+7;
    vector<int>dp;
    int n;
    int fun(int i,string &text){
        if(i==n/2&&(n&1)){
            return 1;
        }
        if(i==n/2){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxi=INT_MIN;

        for(int it=i;it<n;it++){
            if(it==n/2){
                maxi=max(1,maxi);
                break;
            }
            if(grid[i][it]==grid[n-it-1][n-i-1]){
                maxi=max(maxi,2+fun(it+1,text));
            }

        }
        return dp[i]=maxi;




    }
    int longestDecomposition(string text) {
        n=text.size();
        vector<long long>powy;
        long long mul=1;
        for(int i=0;i<n;i++){
            powy.push_back(mul);
            mul*=27;
            mul%=mod;
        }

        grid.resize(n,vector<int>(n,-1));
        dp.resize(n,-1);
        for(int i=0;i<n;i++){
            long long c=0;
            

            for(int j=i,k=0;j<n;j++,k++){
                c+=((text[j]-'a')+1)*powy[k];
                c%=mod;
                grid[i][j]=c;
            }
        }
        return fun(0,text);
        
    }
};