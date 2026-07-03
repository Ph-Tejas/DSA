class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>ans;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums1[i]+nums2[0],i,0});
        }
        while(!pq.empty() && k--){
            int sum=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(j!=m-1){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
            }


        }
        return ans;



    }
};