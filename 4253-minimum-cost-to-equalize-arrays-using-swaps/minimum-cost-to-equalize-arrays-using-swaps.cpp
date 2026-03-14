class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp1;
        map<int,int>mp2;
        int n=nums1.size();
        int cost=0;
        for(int i=0;i<n;i++){
            mp1[nums1[i]]++;

        }
        for(int i=0;i<n;i++){
            if(mp1.find(nums2[i])!=mp1.end()){
                mp1[nums2[i]]--;
                if(mp1[nums2[i]]==0){
                    mp1.erase(nums2[i]);
                }

            }
            else mp2[nums2[i]]++;

        }
        for(auto val:mp1){
            if(val.second&1){
                return -1;
            }
            cost+=val.second/2;
        }
        for(auto val:mp2){
            if(val.second&1){
                return -1;
            }
            cost+=val.second/2;
        }
        
        return cost/2;
    }
};