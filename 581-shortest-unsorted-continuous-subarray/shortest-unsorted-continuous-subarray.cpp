class Solution {
public:
    int solve1(vector<int>&nums){
        int n=nums.size();
        vector<int>v={nums[0]};
        for(int i=1;i<n;i++){
            if(v.back()<=nums[i]){
                v.push_back(nums[i]);
            }
            else break;
        }
        int mini=INT_MAX;
        for(int i=v.size();i<n;i++){
            mini=min(nums[i],mini);
        }
        int ind=upper_bound(v.begin(),v.end(),mini)-v.begin();
        return ind;

    }
    int solve2(vector<int>&nums){
        int n=nums.size();
        vector<int>v={nums[n-1]};
        for(int i=n-2;i>-1;i--){
            if(v.back()>=nums[i]){
                v.push_back(nums[i]);
            }
            else break;
        }
        int maxi=INT_MIN;
        for(int i=n-v.size()-1;i>-1;i--){
            maxi=max(nums[i],maxi);
        }
        int ind=n;
        for(int i=0;i<v.size();i++){
            if(v[i]<maxi){
                ind=i;
                break;
            }
        }
        return ind;

    }
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int a=solve1(nums);
        if(a==n)return 0;
        
        int b=solve2(nums);
        cout<<a<<" "<<b<<endl;
        return max(0,(n-b)-a);
        
    }
};