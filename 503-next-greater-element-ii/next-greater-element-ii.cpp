class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }

        vector<int>ans(n,-1);
        stack<pair<int,int>>st;
        
        for(int i=0;i<2*n;i++){
            int curr=nums[i];
            while(!st.empty() && st.top().first<curr)    {
                if(i%n!=st.top().second){
                    if(st.top().second<n)ans[st.top().second]=curr;
                    st.pop();
                }
            }
            st.push({curr,i});
        }
        return ans;





    }
};