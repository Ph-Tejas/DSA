class TreeAncestor {
public:
    vector<vector<int>>dp;
    TreeAncestor(int n, vector<int>& parent) {
        
        dp.resize(n,vector<int>(31,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=parent[i];
        }
        for(int i=1;i<31;i++){

            for(int j=0;j<n;j++){
                if(dp[j][i-1]==-1)continue;

                dp[j][i]=dp[dp[j][i-1]][i-1];



            }


        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<31;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

    }

    
    int getKthAncestor(int node, int k) {

        int origin=node;
        int it=0;
        while(k>0){
            if((k)&1){
                origin=dp[origin][it];
                if(origin==-1)break;
            }
            k/=2;
            it++;
        }
        return origin;
        



    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */