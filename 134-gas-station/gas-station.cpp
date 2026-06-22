class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int>gass=gas;
        for(int i=0;i<n;i++){
            gas[i]-=cost[i];
            gass[i]-=cost[i];
        }
        int maxi=gas[n-1];
        int ind=n-1;
        for(int i=n-2;i>-1;i--){
            gas[i]+=gas[i+1];
            if(maxi<gas[i]){
                maxi=gas[i];
                ind=i;
            }
        }
        if (maxi<0){
            return -1;

        }
        int curr=gass[ind];
        for(int i=(ind+1)%n;i!=ind;i++,i%=n){
            
            curr+=gass[i];
            cout<<curr;
            if(curr<0)return -1;
        }
        return ind;

    }
};