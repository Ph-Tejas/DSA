class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                int ct=0;
                if(i==j)continue;
                for(int it=0;it<n;it++){
                    int curr=nums[it];
                    if(it&1){
                        ct+=min({abs(j-(curr%k)),abs(k+j-(curr%k)),abs((curr%k)-(j-k))});

                    }
                    else{
                        ct+=min({abs(i-(curr%k)),abs(k+i-(curr%k)),abs((curr%k)-(i-k))});
                    }

                }
                mini=min(mini,ct);
                




            }
        }
        return mini;
    }
};