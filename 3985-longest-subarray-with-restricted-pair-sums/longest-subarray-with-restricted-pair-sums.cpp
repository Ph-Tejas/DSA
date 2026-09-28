class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n=nums.size();
        int msz=n;
        vector<pair<int,int>>v;
        
        for(int i=0;i<n-2;i++){
            unordered_map<int,int>st;
            int a=nums[i];
            st[a]++;
            st[nums[i+1]]++;
            for(int j=i+2;j<n;j++){
                int b=nums[j];
                if(st[a+b]>0 || ((st[a-b]>1 && a-b==a) || (st[a-b]>0 && a-b!=a)) || ((st[b-a]>1 && b-a==a) || (st[b-a]>0 && b-a!=a))){
                    if(v.empty()){
                        v.push_back({i,j});
                        break;
                    }
                    else{
                        while(!v.empty() && v.back().second>=j){
                            v.pop_back();
                            
                        }
                        v.push_back({i,j});
                        break;
                    }
                }
                st[b]++;
                
            }
        }

        n=v.size();
        if(n==0)return msz;
        int ans=0;
        for(int i=0;i<n;i++){
            int l=v[i].first;
            int r=v[i].second;
                
            if(i==0){
                ans=max(ans,r);
                if(i==n-1)ans=max(ans,msz-(l+1));
                else{
                    int rr=v[i+1].second;
                    rr--;
                    ans=max(ans,rr-l);
                }
                
            }
            else{
                if(i==n-1)ans=max(ans,msz-(l+1));
                else{
                    int rr=v[i+1].second;
                    rr--;
                    ans=max(ans,rr-l);
                }

            }


        }
        return ans;


    }
};