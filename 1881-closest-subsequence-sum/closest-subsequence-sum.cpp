class Solution {
public:
    
    void create(vector<int>&v,int &sz1,int i,int sum,vector<int>&sum1){
        if(i==sz1){
            sum1.push_back(sum);
            return;
        }
        int curr=v[i];
        sum1.push_back(sum+v[i]);
        create(v,sz1,i+1,sum+v[i],sum1);
        create(v,sz1,i+1,sum,sum1);



    }
    void create2(vector<int>&v,int &sz1,int i,int sum,set<int>&sum2){
        if(i==sz1){
            sum2.insert(sum);
            return;
        }
        int curr=v[i];
        sum2.insert(sum+v[i]);
        create2(v,sz1,i+1,sum+curr,sum2);
        create2(v,sz1,i+1,sum,sum2);



    }
    


    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>v1;
        vector<int>v2;
        vector<int>sum1;
        set<int>sum2;
        for(int i=0;i<n/2;i++){
            v1.push_back(nums[i]);
        }
        for(int i=n/2;i<n;i++){
            v2.push_back(nums[i]);
        }
        int sz1=v1.size();
        int sz2=v2.size();
        create(v1,sz1,0,0,sum1);
        create2(v2,sz2,0,0,sum2);
        int mini=abs(goal);
        for(int i=0;i<sum1.size();i++){
            int curr=sum1[i];
            auto it=sum2.lower_bound(goal-curr);
            
            if(it!=sum2.end())mini=min(mini,abs((*it)+curr-goal));
            if(it!=sum2.begin()){
                it--;
            }
            mini=min(mini,abs((*it)+curr-goal));

        }
        return mini;

        

    }
};