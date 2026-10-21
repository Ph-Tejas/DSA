class Solution {
public:
    vector<int>bits;
    int n;
    void update(int value,int id){
        while(id<=n){
            bits[id]+=value;
            id+=(id&(-id));
        }
    }
    int query(int n){
        int ans=0;
        int id=n;
        while(id>0){
            ans+=bits[id];
            id-=(id&(-id));
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        vector<pair<int,int>>v;
        bits.resize(n+1);
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n);
        
        for(int i=0;i<n;i++){
            int id=v[i].second;
            update(1,id+1);

            ans[id]=query(n)-query(id+1);
        }
        return ans;
    }
};