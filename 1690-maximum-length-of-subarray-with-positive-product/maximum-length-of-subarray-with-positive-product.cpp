class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        nums.insert(nums.begin(),0);
        nums.push_back(0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0)nums[i]=1;
            if(nums[i]<0)nums[i]=-1;
        }
        long long h=1;
        int p1=-1;
        int p2=-1;
        int n1=-1;
        int n2=-1;
        int maxi=0;
        

        for(int i=1;i<n;i++){
            if(h>0){
                if(p1==-1)p1=i;
                p2=i;
            }
            if(h<0){
                if(n1==-1)n1=i;
                n2=i;
            }
            if(nums[i]==0){
                h=1;
                if(n1!=-1){
                    maxi=max(maxi,n2-(n1-1));
                }
                if(p1!=-1){
                    maxi=max(maxi,p2-(p1-1));
                }
                n1=-1;
                n2=-1;
                p1=-1;
                p2=-1;
                

                continue;
            }
            cout<<h<<" ";
            h*=nums[i];

        }
        return maxi-1;







    }
};