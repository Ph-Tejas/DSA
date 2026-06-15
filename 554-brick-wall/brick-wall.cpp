class Solution {
public:
    int leastBricks(vector<vector<int>>& wall1) {
        vector<vector<long long>>wall;
        long long n=wall1.size();
        map<long long,long long>mp;
        for(int i=0;i<n;i++){
            vector<long long>v;
            for(int j=0;j<wall1[i].size();j++){
                v.push_back(wall1[i][j]);
            }
            wall.push_back(v);
        }
        for(long long i=0;i<n;i++){
            for(long long j=0;j<wall[i].size()-1;j++){
                if(j==0){
                    mp[wall[i][0]]++;
                    continue;
                }
                wall[i][j]=wall[i][j-1]+wall[i][j];
                mp[wall[i][j]]++;
            }

        }
        long long maxi=0;
        long long ans=n;
        for(auto val:mp){
            if(maxi<val.second){
                maxi=val.second;
                ans=n-maxi;
            }
        }
        return ans;
    }
};