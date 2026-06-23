class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int anas=0;
        int ct=1e9;
        while(!st.empty()){
            auto it=st.begin();
            int val=(*it);
            int ct=1;
            for(int i=val+1;;i++){
                if(st.find(i)!=st.end()){
                    ct++;
                    st.erase(i);
                }
                else break;
            }
            for(int i=val-1;;i--){
                if(st.find(i)!=st.end()){
                    ct++;
                    st.erase(i);
                }
                else break;
            }
            st.erase(val);
            anas=max(anas,ct);
            



        }
        return anas;
    }
};