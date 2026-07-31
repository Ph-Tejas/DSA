class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();

        vector<vector<int>>va;
        
        for(int i=0;i<n;i++){
            va.push_back({a[i]+b[i],i});
        }

        sort(va.begin(),va.end());
        
        bool turn=false;
        int ans=0;
        while(!va.empty()){
            
            int ind=va.back()[1];
            if(turn){
                ans-=b[ind];
            }
            else ans+=a[ind];
            turn=(!turn);
            va.pop_back();
            
        }
        if(ans>0)return 1;
        if(ans<0)return -1;
        return 0;



    }
};