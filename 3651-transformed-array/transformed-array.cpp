class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            if(curr<0){
                curr=abs(curr);
                if(curr>i){
                    curr-=i+1;
                    curr%=n;
                }
                else{
                    result[i]=nums[i-curr];
                    continue;
                }
                result[i]=nums[n-1-curr];
            }
            else if(curr>0){
                if(n-1-i<curr){
                    curr-=n-i;
                    curr%=n;
                }
                else {
                    result[i]=nums[curr+i];
                    continue;
                }
                

                result[i]=nums[curr];
                

            }
            else{
                result[i]=curr;
            }
        }
        return result;
    }
};