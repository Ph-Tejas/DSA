class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>ans={0,1};
        if(n==1)return ans;
        int ct=1;
        while(ct<n){
            int it=ans.size()-1;
            int ref=ans.size();
            while(it>-1){
                ans.push_back(ref+ans[it]);
                it--;
            }
            ct++;
        }
        return ans;


    }
};