class Solution {
public:
    int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>frw(n);
        vector<int>bck(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);

            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    frw[st.top()]=i;
                    st.pop();

                }
                st.push(i);
            
            }
        }
        while(!st.empty()){
            frw[st.top()]=n;
            st.pop();
        }
        for(int i=n-1;i>-1;i--){
            if(st.empty()){
                st.push(i);

            }
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    bck[st.top()]=i;
                    st.pop();

                }
                st.push(i);
            
            }
        }
        while(!st.empty()){
            bck[st.top()]=-1;
            st.pop();
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=((((((long long)(frw[i]-i-1)*(i-bck[i]-1))+(1+(frw[i]-i-1)+(i-bck[i]-1)))%mod)*(arr[i])))%mod;
            ans%=mod;
        }
        return ans;


    }
};