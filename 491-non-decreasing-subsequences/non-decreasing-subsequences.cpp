class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void fun(int i,vector<int>& nums,vector<int>&s){
        if(s.size()>=2)ans.push_back(s);
        if(i==n)return ;
        if(s.empty()||nums[i]>=s.back()){
            s.push_back(nums[i]);
            fun(i+1,nums,s);
            s.pop_back();
            fun(i+1,nums,s);
        }
        else{
            fun(i+1,nums,s);
        }



    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int>s;
        fun(0,nums,s);
        set<vector<int>>st;
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }
        ans.clear();
        for(auto &val:st){
            ans.push_back(val);
        }
        return ans;
    }
};