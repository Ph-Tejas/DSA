class Solution {
public:
    int fun(int i,int j,vector<int>&nums){
        if(i>j)return INT_MIN;
        int loc=-1;
        int fst=-1;
        bool flag=false;
        int prod=1;

        for(int k=i;k<=j;k++){
            if(nums[k]<0){
              
                if(!flag){
                    fst=k;
                    flag=true;
                }
                loc=k;
            }
            prod*=nums[k];
        }
        if(prod<0){
            int p1=1;
            bool f1=false;
            bool f2=false;
            bool f3=false;
            bool f4=false;
            
            int p2=1;
            int p3=1;
            int p4=1;
            for(int k=i;k<loc;k++){
                p1*=nums[k];
                f1=true;
            }
            if(!f1)p1=INT_MIN;
            
            for(int k=loc+1;k<=j;k++){
                p2*=nums[k];
                f2=true;
            }
            if(!f2)p2=INT_MIN;

            for(int k=i;k<fst;k++){
                p3*=nums[k];
                f3=true;
            }
            if(!f3)p3=INT_MIN;
            for(int k=fst+1;k<=j;k++){
                p4*=nums[k];
                f4=true;
            }
            if(!f4)p4=INT_MIN;

            return max({p1,p2,p3,p4,prod});

            
            
        }
        return prod;

    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>zeros;
        zeros.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeros.push_back(i);
            }
        }
        zeros.push_back(n);
        int maxi=INT_MIN;
        if(zeros.size()>2)maxi=0;
        
        int sz=zeros.size();
        vector<vector<int>>ranges;
        for(int i=0;i<sz-1;i++){
            maxi=max(maxi,fun(zeros[i]+1,zeros[i+1]-1,nums));
        }
        return maxi;


    }
};