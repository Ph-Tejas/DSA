class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hfence, vector<int>& vfence) {
        
        set<int>st;
        hfence.insert(hfence.begin(),1);
        hfence.push_back(m);
        sort(hfence.begin(),hfence.end());
        for(int i=0;i<hfence.size();i++){
            for(int j=i+1;j<hfence.size();j++){

                st.insert(hfence[j]-hfence[i]);
            }
        }

        vfence.insert(vfence.begin(),1);
        vfence.push_back(n);

        sort(vfence.begin(),vfence.end());
        long long maxi=-1;
        for(int i=0;i<vfence.size();i++){
            for(int j=1;j<vfence.size();j++){
                if(st.find(vfence[j]-vfence[i])!=st.end()){
                    if(maxi<vfence[j]-vfence[i]){
                        maxi=vfence[j]-vfence[i];
                    }
                }
            }
        }
        
        if(maxi==-1)return -1;

        return (maxi*maxi)%((long long)1e9+7);


        
    }
};