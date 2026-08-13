class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();


        int a=0;
        int b=0;
        vector<int>v(32);
        int num;
        for(int i=0;i<31;i++){
            for(int j=0;j<n;j++){
                num=nums[j];

                if((num>>i)&1){
                    v[i]++;
                }
            }
        }
        int ind;
        for(int i=0;i<31;i++){
            if(v[i]&1){
                ind=i;
                break;
            }

        }
        for(int j=0;j<n;j++){
            int num=nums[j];
            if((num>>ind)&1){
                a=(a^num);
            }
            else b=(b^num);
        }

        return {a,b};
    





    }
};