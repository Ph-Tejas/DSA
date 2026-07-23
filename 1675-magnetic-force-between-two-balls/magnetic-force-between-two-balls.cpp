class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int mini=0;
        int maxi=1e9;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            int k=m-1;
            for(int i=0;i<n;i++){
                int loc=(upper_bound(position.begin(),position.end(),position[i]+mid)-position.begin());
                if(loc==n)break;
                k--;
                i=loc-1;



            }
            if(k<=0){
                mini=mid+1;
            }
            else maxi=mid-1;
        }
        return mini;
    }
};