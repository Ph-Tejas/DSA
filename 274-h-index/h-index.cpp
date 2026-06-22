class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int maxi=0;
        sort(citations.begin(),citations.end());
        for(int i=0;i<n;i++){
            maxi=max(maxi,min(citations[i],n-i));
            
        }
        return maxi;
    }
};