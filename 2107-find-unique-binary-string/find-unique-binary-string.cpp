class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        int sz=nums[0].size();
        vector<int>v(1<<sz);
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<sz;j++){
                sum+=(nums[i][j]-'0')*(1<<(sz-1-j));
            }
            v[sum]++;

        }
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                string ans;
                for(int k=0;k<sz;k++){
                    if((i>>(sz-1-k))&1){
                        ans.push_back('1');
                    }
                    else ans.push_back('0');
                }
            return ans;
            }
        }
        return "";
         

    }
};