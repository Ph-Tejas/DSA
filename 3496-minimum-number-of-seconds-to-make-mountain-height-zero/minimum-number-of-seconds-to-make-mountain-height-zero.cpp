class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTime) {
        long long mini=0;
        long long maxi=1e18;
        long long mid1=mini+(maxi-mini)/2;
        
        int sz=workerTime.size();
        while(maxi>=mini){
            int mH=mountainHeight;
            for(int i=0;i<sz;i++){
                
                long long curr=workerTime[i];
                long long val=sqrt((mid1/curr)*2)+1;
                if(curr*((val*(val+1))/2)<=mid1){
                    mH-=val;
                }
                else if(curr*((val*(val-1))/2)<=mid1){
                    mH-=val-1;
                }
                else{
                    mH-=val-2;
                }
                

                // long long lo=0;
                // long long hi=1e6;
                // long long mid=lo+(hi-lo)/2;
                // while(lo<=hi){
                //     if(curr*((mid*(mid+1))/2)<=mid1){
                //         lo=mid+1;

                //     }
                //     else hi=mid-1;
                //     mid=lo+(hi-lo)/2;

                // }
                // mH-=hi;
                if(mH<=0)break;
            }
            if(mH<=0){
                maxi=mid1-1;
            }
            else {
                mini=mid1+1;
            }

            mid1=mini+(maxi-mini)/2;
        }
        return mini;
    }
};