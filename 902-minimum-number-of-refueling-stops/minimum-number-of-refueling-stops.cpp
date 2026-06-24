class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        sort(stations.begin(),stations.end());
        stations.push_back({target,0});
        int n=stations.size();
        
        priority_queue<int>pq;
        int it=0;
        int ans=0;
        while(true){
            while(stations[it][0]<=startFuel){
                if(it==n-1)return ans;
                pq.push(stations[it][1]);
                it++;

            }
            if(it==n){
                break;
            }
            if(pq.empty())return -1;
            startFuel+=pq.top();
            pq.pop();
            ans++;
        }
        return ans;




    }
};