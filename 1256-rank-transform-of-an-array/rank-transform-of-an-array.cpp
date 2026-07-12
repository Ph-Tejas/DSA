class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        map<int,int>st;
        for(int i=0;i<n;i++){
            st[arr[i]]=(0);
        }
        int it=1;
        for(auto &val:st){
            val.second=it;
            it++;
        }

        for(int i=0;i<n;i++){
            arr[i]=st[arr[i]];
        }
        return arr;

    }
};