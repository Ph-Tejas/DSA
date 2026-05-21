class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string>st;
        int n=arr1.size();
        int m=arr2.size();

        for(int i=0;i<n;i++){
            string s=to_string(arr1[i]);
            string k;
            for(int j=0;j<s.size();j++){
                k.push_back(s[j]);
                st.insert(k);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            string s=to_string(arr2[i]);
            string k;
            for(int j=0;j<s.size();j++){
                k.push_back(s[j]);
                if(st.find(k)!=st.end()){
                    ans=max(ans,j+1);
                }
            }
        }
        return ans;
    }
};