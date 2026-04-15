class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void fun(vector<int>& nums,int vis,vector<int>s){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }

        for(int i=0;i<n;i++){
            if(((vis>>(i))&1)==0){
                s.push_back(nums[i]);
                int new_vis=(vis|(1<<i));
                fun(nums,new_vis,s);
                s.pop_back();

            }

            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++){
            fun(nums,(1<<i),{nums[i]});
        }    
        return ans;
    }
};