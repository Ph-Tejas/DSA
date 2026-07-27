class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        vector<int>v(n);

        for(int i=1;i<n;i++){
            v[i]=(max(0,heights[i]-heights[i-1]));
        }
        int mini=0;
        int maxi=n-1;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            bool flag=false;
            vector<int>v1;
            for(int i=0;i<=mid;i++){
                v1.push_back(v[i]);
            }
            int l=ladders;
            sort(v1.begin(),v1.end());
            if(l>=mid+1)flag=true;
            while(!v1.empty() && l--){
                v1.pop_back();
            }
            int sum=accumulate(v1.begin(),v1.end(),0);
            if(sum<=bricks)flag=true;
            if(flag)mini=mid+1;
            else maxi=mid-1;
        }
        return maxi;
    }
};