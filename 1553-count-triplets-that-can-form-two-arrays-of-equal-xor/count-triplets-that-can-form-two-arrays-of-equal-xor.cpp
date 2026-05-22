class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        mp[0]++;
        mp[arr[0]]++;
        for(int i=0;i<n;i++){
            
            if(i==0)continue;
            arr[i]=(arr[i]^arr[i-1]);
            mp[arr[i]]++;
        }
        int ans=0;
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]==(arr[j]^arr[i]))ans++;
            }
        }
        for(int I=0;I<n;I++){
            for(int i=I+1;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if((arr[i]^arr[I])==(arr[j]^arr[i]))ans++;
                }
            }
        }

        return ans;

    }
};