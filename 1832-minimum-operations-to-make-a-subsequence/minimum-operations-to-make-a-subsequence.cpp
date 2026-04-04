class Solution {
public:
    int LIS(vector<int>&v){
        vector<int>ref;
        for(int i=0;i<v.size();i++){
            auto it=lower_bound(ref.begin(),ref.end(),v[i]);
            if(it==ref.end()){
                ref.push_back(v[i]);
            }
            else ref[it-ref.begin()]=v[i];
        }
        return ref.size();
    }
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n=target.size();
        int m=arr.size();
        map<int,int>mp;
        vector<int>newArr;
        for(int i=0;i<n;i++){
            mp[target[i]]=i;
        }
        for(int i=0;i<m;i++){
            if(mp.find(arr[i])!=mp.end()){
                newArr.push_back(mp[arr[i]]);
            }
        }
        int ans=LIS(newArr);
        return target.size()-ans;

    }
};