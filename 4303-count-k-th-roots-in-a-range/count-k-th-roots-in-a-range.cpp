class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return r-l+1;
        }
        vector<int>powy;
        for(int i=0;;i++){

            long long p=pow(i,k);
            if(p>1e9)break;
            powy.push_back(p);
        }
        int ct=0;
        for(int i=0;i<powy.size();i++)
{
    if(powy[i]>=l&&powy[i]<=r)ct++;
}
return ct;    
}
};