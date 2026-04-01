class Solution {
public:
    int range,n;
    vector<int>vis;
    int fun(int ind,vector<int>& arr){
        if(vis[ind]!=-1)return vis[ind];
        int maxi=1;
        for(int j=-1;j>=-1*range;j--){
            if((ind+j>=0)&&(arr[ind+j]<arr[ind])){
                
                maxi=max(maxi,1+fun(ind+j,arr));
            }
            else break;
        }
        for(int j=1;j<=range;j++){
            if((ind+j<n)&&(arr[ind+j]<arr[ind])){
                
                maxi=max(maxi,1+fun(ind+j,arr));
            }
            else break;
        }
        return vis[ind]=maxi;
    
    }

    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        int maxi=-1;
        range = d;
        vis.resize(n,-1);
        for(int i=0;i<n;i++){
            maxi=max(maxi,fun(i,arr));
         
        }
        return maxi;
    }
};