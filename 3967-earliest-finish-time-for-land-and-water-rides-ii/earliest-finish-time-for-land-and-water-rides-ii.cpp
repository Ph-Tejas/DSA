class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        //water first
        int w_val1=1e9;
        for(int i=0;i<m;i++) {
            w_val1 = min(w_val1,waterStartTime[i]+waterDuration[i]);
        }
        int l_val1=1e9;
        for(int i=0;i<n;i++) {
            if(landStartTime[i]<=w_val1) {
                l_val1 = min(l_val1,w_val1+landDuration[i]);
            } else {
                l_val1 = min(l_val1,landStartTime[i]+landDuration[i]);
            }
        }

        //land first
        int l_val2=1e9;
        
        for(int i=0;i<n;i++) {
            l_val2 = min(l_val2,landStartTime[i]+landDuration[i]);
        }

        int w_val2=1e9;
        for(int i=0;i<m;i++) {
            if(waterStartTime[i]<=l_val2) {
                w_val2 = min(w_val2,l_val2+waterDuration[i]);
            } else {
                w_val2 = min(w_val2,waterStartTime[i]+waterDuration[i]);
            }
        }

        return min(l_val1,w_val2);
        
        
    }
};