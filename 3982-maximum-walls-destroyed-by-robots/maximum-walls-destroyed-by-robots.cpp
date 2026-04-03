class Solution {
public:
    int countWalls(vector<int>& walls,int l,int r,int &m){
        int mini=0;
        int maxi=m-1;
        int mid=mini+(maxi-mini)/2;
        int a,b;
        while(maxi>=mini){
            if(walls[mid]>=l){
                maxi=mid-1;
            }
            else{
                mini=mid+1;
            }



            mid=mini+(maxi-mini)/2;
        }
        
        a=maxi+1;
        mini=0;
        maxi=m-1;
        mid=mini+(maxi-mini)/2;
        while(maxi>=mini){
            if(walls[mid]<=r){
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }



            mid=mini+(maxi-mini)/2;
        }
        b=m-mini;
        return m-a-b;


    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        int m=walls.size();
        vector<vector<int>>mainRobots;
        for(int i=0;i<n;i++){
            mainRobots.push_back({robots[i],distance[i]});
        }
        sort(walls.begin(),walls.end());

        sort(mainRobots.begin(),mainRobots.end());
        vector<vector<int>>wallCount(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            int range=mainRobots[i][1];
            int pos=mainRobots[i][0];
            int l,r;
            l=pos-range;
            if(i!=0)l=max(l,mainRobots[i-1][0]+1);
            r=pos;
            wallCount[i][0]=countWalls(walls,l,r,m);
            l=pos;
            r=pos+range;
            if(i!=n-1)r=min(r,mainRobots[i+1][0]-1);
            wallCount[i][1]=countWalls(walls,l,r,m);
        }
        vector<int>actualWalls(n-1);
        for(int i=0;i<n-1;i++){
            actualWalls[i]=countWalls(walls,mainRobots[i][0],mainRobots[i+1][0],m);
        }
        vector<vector<int>>dp(4,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            int maxl=max(dp[0][i-1],dp[1][i-1]);
            int maxr=max(dp[2][i-1],dp[3][i-1]);
            int l=wallCount[i-1][0];
            int r=wallCount[i-1][1];
            if(i==1){

                dp[0][i]=maxl+l;
                dp[1][i]=maxr+l;
                dp[2][i]=maxl+r;
                dp[3][i]=maxr+r;
            }
            else{
                dp[0][i]=maxl+l;
                dp[2][i]=maxl+r;
                dp[3][i]=maxr+r;
                int overlap = max(0, wallCount[i-2][1] + wallCount[i-1][0] - actualWalls[i-2]);
                dp[1][i] = maxr + wallCount[i-1][0] - overlap;
            
            }
        }
        return max({dp[0][n],dp[1][n],dp[2][n],dp[3][n]});
    }
};