class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();

        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({trips[i][1],trips[i][0]});
            v.push_back({trips[i][2],-1*trips[i][0]});
        }
        sort(v.begin(),v.end());
        int maxi=0;
        int h=0;
        for(int i=0;i<n*2;i++){
            h+=v[i].second;
            maxi=max(maxi,h);
        }
        return ((maxi>capacity)?false:true);






    }
};