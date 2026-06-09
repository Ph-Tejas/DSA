class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<bool>state(n,false);
        bool flag=false;
        int st=0;
        int ct=0;
        while(!flag){
            ct++;
            bool comm=false;
            for(int i=st;i<n&&!comm;i++){
                bool ans=false;
                state[arr[i]]=true;
                for(int j=i;j>=st;j--){
                    if(state[j]==false){
                        ans=true;
                        break;
                    }
                }
                if(!ans){
                    comm=true;
                }
            }
            while(state[st]){
                st++;
                if(st==n){
                    flag=true;
                }
            }
        }
        return ct;
    }
};