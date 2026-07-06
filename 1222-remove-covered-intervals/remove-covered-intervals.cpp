class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        unordered_map<int,int>mp;
        int prev=-1;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int a=intervals[i][0];
            int b=intervals[i][1]-1;
            if(prev>=b)continue;
            mp[a]=b;
            prev=max(prev,b);


            
        }
        return mp.size();




    }
};