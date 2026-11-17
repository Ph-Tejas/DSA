class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>v(n);
        vector<int>tmp;
        for(int i=n-1;i>-1;i--){
            tmp.push_back(nums[i]);
            sort(tmp.begin(),tmp.end());
            v[i]=tmp;
        }
        int diff=INT_MAX;
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                int sum=nums[i]+nums[j];
                int tgt=target-sum;
                auto it=lower_bound(v[j+1].begin(),v[j+1].end(),tgt);
                if(it==v[j+1].end()){
                    it--;
                    if(diff>abs(tgt-(*it))){
                        diff=abs(tgt-(*it));
                        ans=sum+(*it);
                    }
                }
                if(it==v[j+1].end()){
                    it--;
                    if(diff>abs(tgt-(*it))){
                        diff=abs(tgt-(*it));
                        ans=sum+(*it);
                    }
                }
                else{
                    if(diff>abs(tgt-(*it))){
                        diff=abs(tgt-(*it));
                        ans=sum+(*it);
                    }
                    if(it!=v[j+1].begin()){
                        it--;
                        if(diff>abs(tgt-(*it))){
                            diff=abs(tgt-(*it));
                            ans=sum+(*it);
                        }
                    }
                }
            }
        }

        return ans;

    }


};