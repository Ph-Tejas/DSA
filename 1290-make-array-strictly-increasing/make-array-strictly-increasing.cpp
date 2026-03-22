
class Solution {
public:


    map<pair<int,int>, int> mp;
    int fun(int ind,int prev,vector<int>& arr1, vector<int>& arr2){
        if(ind==arr1.size())return 0;
        if(mp.find({ind,prev})!=mp.end()){
            return mp[{ind,prev}];
        }
        int changing;
        int notChanging;
        auto it=upper_bound(arr2.begin(),arr2.end(),prev);
        if(it==arr2.end()){
            changing=1e9;
        }
        else {
            int val=(*it);
            changing=1+fun(ind+1,val,arr1,arr2);
        }
        if(arr1[ind]<=prev){
            notChanging=1e9;
            
        }
        else{
            notChanging=fun(ind+1,arr1[ind],arr1,arr2);
            
        }
        return mp[{ind,prev}]=min(changing,notChanging);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();
        sort(arr2.begin(),arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int ans=fun(0,-1,arr1,arr2);
        if(ans>=1e9)return -1;
        return ans;







    }
};