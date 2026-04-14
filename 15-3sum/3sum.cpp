class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> frq;
        for(auto el:nums) frq[el]++;
        vector<int> a;
        a.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) continue;
            a.push_back(nums[i]);
        }
        n=a.size();
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(a[i]>0) break;
            for(int j=i+1;j<n;j++){
                if(a[i]+a[j]>0) break;
                auto it=lower_bound(a.begin()+j+1,a.end(),0-a[i]-a[j]);
                if(it!=a.end() && (*it)==(0-a[i]-a[j])){
                    ans.push_back({a[i],a[j],0-a[i]-a[j]});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==0) continue;
            if(((-1*a[i])%2)==0){
                if(frq.find((-1*a[i])/2)!=frq.end() && frq[(-1*a[i])/2]>=2){
                    ans.push_back({a[i],-1*(a[i]/2),-1*(a[i]/2)});
                }
            }
        }
        if(frq[0]>=3) ans.push_back({0,0,0});
        return ans;
    }
};