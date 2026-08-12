class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();


        for(int i=0;i<n;i++){
            if(hours[i]>8){
                hours[i]=1;

            }
            else hours[i]=-1;
        }
        vector<int>v(2e5+1,INT_MAX);
        
        for(int i=1;i<n;i++){
            hours[i]+=hours[i-1];

        }
        for(int i=n-1;i>-1;i--){
            v[1e5+hours[i]]=i;
        }
        
        int mini=INT_MAX;
        for(int i=0;i<2e5+1;i++){
            mini=min(mini,v[i]);
            v[i]=mini;
        }

        int maxi=INT_MIN;
        for(int i=n-1;i>-1;i--){
            int curr=hours[i];
            if(curr>0){
                maxi=max(maxi,i+1);

            }
            else{
                if(v[(curr-1)+1e5]!=INT_MAX){
                    maxi=max(maxi,max(i-v[(curr-1)+1e5],0));
                }
                else maxi=max(maxi,0);
            }

        }
        return maxi;


        




    }
};