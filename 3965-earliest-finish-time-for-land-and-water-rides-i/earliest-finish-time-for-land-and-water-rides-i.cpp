class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int mini=INT_MAX;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0;i<n;i++){   
            int en=landStartTime[i]+landDuration[i];
            for(int j=0;j<m;j++){
                mini=min(mini,max(waterStartTime[j],en)+waterDuration[j]);
            }

        }
        for(int i=0;i<m;i++){   
            int en=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<n;j++){
                mini=min(mini,max(landStartTime[j],en)+landDuration[j]);
            }

        }
        return mini;
    }
};