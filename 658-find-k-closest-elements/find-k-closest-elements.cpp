class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int it1=0;
        if(n==1)return {arr[0]};
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            if(abs(arr[i]-x)<mini){
                mini=abs(arr[i]-x);
                it1=i;
            }
        }
        int it2;
        if(it1==0)it2=1;
        else if(it1==n-1){
            it1==n-2;
            it2==n-1;
        }
        else{
            if(abs(arr[it1+1]-x)>=abs(arr[it1-1]-x)){
                it1--;
                it2=it1+1;
            }
            else it2=it1+1;
        }
        cout<<it1<<" "<<it2;
        vector<int>ans;
        while(k--){
            if(it1==-1){
                ans.push_back(arr[it2]);
                it2++;
            }
            else if(it2==n){
                ans.push_back(arr[it1]);
                it1--;
            }
            else{
                if(abs(arr[it1]-x)>abs(arr[it2]-x)){
                    ans.push_back(arr[it2]);
                    it2++;
                }
                else {
                    ans.push_back(arr[it1]);
                    it1--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};