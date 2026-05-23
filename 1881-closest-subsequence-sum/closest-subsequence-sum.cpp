class Solution {
public:
    
    void create(vector<int>&v,int &sz1,int i,int sum,vector<int>&sum1){
        if(i==sz1){
            return;
        }
        int curr=v[i];
        sum1.push_back(sum+v[i]);
        create(v,sz1,i+1,sum+v[i],sum1);
        create(v,sz1,i+1,sum,sum1);



    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>v1;
        vector<int>v2;
        vector<int>sum1,sum2;
        for(int i=0;i<n/2;i++){
            v1.push_back(nums[i]);
        }
        for(int i=n/2;i<n;i++){
            v2.push_back(nums[i]);
        }
        sum1.push_back(0);
        sum2.push_back(0);
        int sz1=v1.size();
        int sz2=v2.size();
        create(v1,sz1,0,0,sum1);
        create(v2,sz2,0,0,sum2);
        sort(sum2.begin(),sum2.end());
        int mini=abs(goal);
        for(int i=0;i<sum1.size();i++){
            int curr=sum1[i];
            auto it=lower_bound(sum2.begin(),sum2.end(),goal-curr);
            if(it!=sum2.end())mini=min(mini,abs((*it)+curr-goal));
            if(it!=sum2.begin()){
                it--;
            }

            mini=min(mini,abs((*it)+curr-goal));

        }
        return mini;

        

    }
};