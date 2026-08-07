class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(arr[i]);
        }
        for(int i=n-2;i>-1;i--){
            v[i]+=v[i+1];
        }
        int tot=v[0];
        int diff=INT_MAX;
        int ans=-1;
        for(int i=0;i<1e5+1;i++){
            auto it=lower_bound(arr.begin(),arr.end(),i);
            int ind=it-arr.begin();
            if(ind==n)break;
            int ct=n-ind;
            int temp=tot;
            temp-=v[ind];
            temp+=ct*i;

            if(diff>abs(temp-target)){
                diff=abs(temp-target);
                ans=i;
            }


        }
        
        return ans;



    }
};