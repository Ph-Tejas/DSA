class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int it=0;
        int ct=0;
        int arrows=1;
        int init=points[it][1];
        for(int i=0;i<n;i++){
            if(init<points[i][0]){
                it=i;
                init=points[it][1];
                arrows++;
            }
        }
        return arrows;



    }
};