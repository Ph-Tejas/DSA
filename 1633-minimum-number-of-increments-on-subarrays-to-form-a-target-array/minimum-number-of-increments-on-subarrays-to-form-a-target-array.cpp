class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        target.insert(target.begin(),0);
        int n=target.size();
        int ans=0;
        bool com=false;
        int mini=0;
        int maxi=0;
        for(int i=0;i<n-1;i++){
            if(target[i]==target[i+1])continue;
            if(!com){
                if(target[i]<target[i+1]){
                    com=true;
                    mini=target[i];
                    maxi=target[i+1];

                }
            }
            else{
                if(target[i]<target[i+1]){
                    maxi=target[i+1];
                }
                else{
                    com=false;
                    ans+=maxi-mini;
                    mini=0;
                    maxi=0;
                }

            }

        }
        ans+=maxi-mini;
        return ans;


    }
};