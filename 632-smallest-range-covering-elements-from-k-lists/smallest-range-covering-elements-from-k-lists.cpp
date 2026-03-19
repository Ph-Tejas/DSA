class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>ptrs(n,0);
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>>pq;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i].size()==1)pq.push({{nums[i][0],1000000000},i});
            else pq.push({{nums[i][0],nums[i][1]},i});
            maxi=max(maxi,nums[i][0]);
        }
        int ans=INT_MAX;
        int l=-1;
        int r=-1;
        while(!pq.empty()){
            int a=pq.top().first.first;
            int b=pq.top().first.second;
            int c=pq.top().second;
            pq.pop();
            if(a==1000000000)break;
            if(ans>maxi-a){
                ans=maxi-a;
                l=a;
                r=maxi;
            }
        
            a=b;

            if(ptrs[c]+1<nums[c].size())b=nums[c][ptrs[c]+1];
            else b=1e9;
            if(a>maxi)maxi=a;
            ptrs[c]++;
            pq.push({{a,b},c});
            

        }
        return {l,r};


        

    }
};