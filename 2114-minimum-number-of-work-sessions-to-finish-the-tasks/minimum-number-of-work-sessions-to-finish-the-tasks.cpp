class Solution {
public:
    int n;
    int tgt;
    int dp[14][20000][16];
    int fun(int i,int vis,int uptill,vector<int>& tasks, int &sessionTime){
        
        if(vis==tgt)return 0;
        if(i==n)return 1e9;
        if(dp[i][vis][uptill]!=-1)return dp[i][vis][uptill];
        int next=n;
        for(int it=i+1;it<n;it++){
            if(((vis>>it)&1)==0){
                next=it;
                break;
            }
        }

        int notPick=fun(next,vis,uptill,tasks,sessionTime);
        int pick=1e9;
        if(uptill+tasks[i]<=sessionTime){
            int newVis=((vis)|(1<<i));
            int restore=n;
            for(int it=0;it<n;it++){

                if(((newVis>>it)&1)==0){
                    restore=it;
                    break;
                }
            }
            int pickButEnd=1+fun(restore,newVis,0,tasks,sessionTime);
            int pickButNotEnd=fun(next,newVis,uptill+tasks[i],tasks,sessionTime);
            pick=min(pickButEnd,pickButNotEnd);
        }
        return dp[i][vis][uptill]=min(pick,notPick);
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        n=tasks.size();
        tgt=(1<<n)-1;
        memset(dp,-1,sizeof(dp));
        if(n==1)return 1;
        return fun(0,0,0,tasks,sessionTime)+1;
    }
};