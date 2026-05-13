class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>v(2*limit+2);
        map<int,int>mp;
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-1-i];
            mp[a+b]++;
            v[min(a,b)+1]++;
            v[max(a,b)+limit+1]--;
        }
        for(int i=1;i<2*limit+2;i++){
            v[i]=v[i-1]+v[i];
        }

        int ans=n/2;
        for(auto val:mp){
            int a=v[val.first]-val.second;
            int c=(n/2)-v[val.first];
            ans=min(ans,(a+2*c));

        }
        return ans;
        
        

    }
};