class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        string s;
        vector<int>ans;
        for(int i=0;i<n;i++){
            s=to_string(nums[i]);
            for(int j=0;j<s.size();j++){
                ans.push_back(s[j]-'0');
            }
        }
        return ans;

    }
};