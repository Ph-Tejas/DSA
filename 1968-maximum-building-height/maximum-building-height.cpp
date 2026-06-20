class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1,0});
        int sz=restrictions.size();
        bool lastIsHere=false;
        for(int i=0;i<sz;i++){
            if(restrictions[i][0]==n){
                lastIsHere=true;
                break;
            }
        }
        if(!lastIsHere){
            restrictions.push_back({n,INT_MAX});
            sz++;
        }
        sort(restrictions.begin(),restrictions.end());
        
        for(int i=0;i<sz-1;i++){
            int c=restrictions[i+1][0]-restrictions[i][0]-1;
            if(restrictions[i][1]>=restrictions[i+1][1]){
                restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+c+1);
                
            }
            else{
                restrictions[i+1][1]=min(restrictions[i+1][1],restrictions[i][1]+c+1);
            }
        }
        for(int i=sz-1;i>0;i--){
            int c=abs(restrictions[i-1][0]-restrictions[i][0])-1;
            if(restrictions[i][1]>=restrictions[i-1][1]){
                restrictions[i][1]=min(restrictions[i][1],restrictions[i-1][1]+c+1);
                
            }
            else{
                restrictions[i-1][1]=min(restrictions[i-1][1],restrictions[i][1]+c+1);
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<sz-1;i++){

            maxi=max(maxi,restrictions[i][1]);
            maxi=max(maxi,restrictions[i+1][1]);
            int c=restrictions[i+1][0]-restrictions[i][0]-1;
            int b=abs(restrictions[i+1][1]-restrictions[i][1]);
            if(restrictions[i][1]>=restrictions[i+1][1]){
                c-=b;
                maxi=max(maxi,restrictions[i][1]+((c+1)/2));
                
            }
            else{
                c-=b;
                maxi=max(maxi,restrictions[i+1][1]+((c+1)/2));
                
            }
        }
        return maxi;
        







    }
};