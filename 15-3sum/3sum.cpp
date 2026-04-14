class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]>0) break;
                auto it=lower_bound(nums.begin()+j+1,nums.end(),0-nums[i]-nums[j]);
                if(it!=nums.end() && (*it)==(0-nums[i]-nums[j])){
                    ans.insert({nums[i],nums[j],(*it)});
                }
            }
        }
        vector<vector<int>> output;
        for(auto el:ans) output.push_back(el);
        return output;
    }
};