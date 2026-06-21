class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        vector<int>c(1e5+1);
        for(int i=0;i<n;i++){
            c[costs[i]]++;
        }

        for(int i=1;i<=1e5;i++){
            c[i]+=c[i-1];
        }
        
        
        vector<int>fin(n);
        for(int i=n-1;i>-1;i--){
            int curr=costs[i];
            c[curr]--;
            fin[c[curr]]=curr;
        }

        int i=0;
        int ct=0;
        while(i<fin.size()&&coins>=fin[i]){
            ct++;
            coins-=fin[i];
            i++;
        }
        return ct;
    }
};