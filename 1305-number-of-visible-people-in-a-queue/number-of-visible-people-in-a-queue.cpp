class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        int n=heights.size();
        stack<int>st;
        vector<int>ans(n);
        st.push(0);
        int i=1;
        while(!st.empty()){
            if(i==n)break;
            int curr=heights[i];
            ans[st.top()]++;
            while(!st.empty()&&heights[st.top()]<curr){
                st.pop();
                if(st.empty())break;
                ans[st.top()]++;

            }
            st.push(i);
            i++;
        }
        return ans;


    }
};