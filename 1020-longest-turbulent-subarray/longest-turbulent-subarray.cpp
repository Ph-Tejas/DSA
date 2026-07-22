class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();

        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1]){
                arr[i]=-2;
            }
            else if(arr[i]>arr[i+1])arr[i]=-1;
        }
        int ans=1;
        int ct=0;

        for(int i=0;i<n;i++){
            if(ct==0){
                
                if(arr[i]==-2||arr[i]==-1)ct++;    
                continue;
            }
            if(arr[i]==-1 && arr[i-1]==-2){
                ct++;
            }
            else if(arr[i]==-2 && arr[i-1]==-1){
                ct++;
            }
            else{
                ans=max(ct+1,ans);
                ct=0;
                i--;
            }

        }
        return ans;




    }
};