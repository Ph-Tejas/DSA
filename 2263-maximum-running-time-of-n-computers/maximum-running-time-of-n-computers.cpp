class Solution {
public:

    bool valid(long long mid,vector<int>& batteries,int &n){
        int sz=batteries.size();

        long long needed=(long long)n*mid;
        long long cur=0;

        for(auto &x:batteries){
            cur+=min((long long)x,mid);
            if(cur>=needed)return true;

        }
        return false;




    }

    long long maxRunTime(int n, vector<int>& batteries) {
        int sz=batteries.size();
        long long mini=0;
        long long maxi=0;

        for(int i=0;i<sz;i++){
            maxi+=batteries[i];
        }
        while(mini<=maxi){
            long long mid=mini+(maxi-mini)/2;

            if(valid(mid,batteries,n)){
                mini=mid+1;
            }
            else maxi=mid-1;



        }
        return maxi;
    }
};