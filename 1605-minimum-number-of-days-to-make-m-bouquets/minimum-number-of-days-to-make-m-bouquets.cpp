class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n)return -1;
        int mini=1;
        int maxi=1e9;
        while(maxi>=mini){
            int mid=mini+(maxi-mini)/2;
            bool flag=true;

            int it=0;
            int ct=0;
            int m_=0;

            for(int i=0;i<n;i++){
                if(bloomDay[i]>mid){
                    it=i+1;
                    ct=0;
                    continue;

                }
                else{
                    ct++;
                    if(ct==k){
                        m_++;
                        it=i+1;
                        ct=0;
                    }
                }



            }
            if(m_<m){
                flag=false;
            }
            if(flag){
                maxi=mid-1;

            }
            else mini=mid+1;

        }
        return mini;
    }
};