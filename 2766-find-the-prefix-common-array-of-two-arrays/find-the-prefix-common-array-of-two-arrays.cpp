class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        set<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(st.find(A[i])!=st.end()){
                st.erase(A[i]);
            }
            else st.insert(A[i]);
            if(st.find(B[i])!=st.end()){
                st.erase(B[i]);
            }
            else st.insert(B[i]);
            ans[i]=(((i+1)*2)-st.size())/2;
        }
        return ans;
    }
};