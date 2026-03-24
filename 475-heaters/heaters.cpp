class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=heaters.size();
        int sz=houses.size();
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        int mini=0;
        int maxi=1e9;
        int mid=mini+(maxi-mini)/2;
        while(maxi>=mini){
            bool response=true;
            vector<int>vis(sz+1);
            for(int i=0;i<n;i++){
                int curr=heaters[i];
                auto it1=lower_bound(houses.begin(),houses.end(),curr-mid);
                auto it2=upper_bound(houses.begin(),houses.end(),curr+mid);
                
                
                vis[it1-houses.begin()]+=1;
                vis[it2-houses.begin()]-=1;
            }
            for(int i=0;i<sz;i++){
                
                if(i!=0) vis[i]+=vis[i-1];
                if(vis[i]<=0){
                    response=false;
                    break;
                }
            }
            if(response){
                maxi=mid-1;
            }
            else{
                mini=mid+1;

            }
            mid=mini+(maxi-mini)/2;

        }
        return mini;

    }
};