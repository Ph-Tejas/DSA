class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removals) {
        int n=s.size();
        int m=p.size();
        int sz=removals.size();
        int mini=0;
        int maxi=sz;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            string temp=s;

            for(int i=0;i<mid;i++){
                temp[removals[i]]='.';
            }
            int it=0;
            for(int j=0;j<n;j++){
                if(it==m)break;
                if(temp[j]==p[it])it++;
            }

            if(it==m){
                mini=mid+1;
            }
            else maxi=mid-1;
















        }
        return maxi;
    }
};