class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>freq(n+1);
        for(int i=0;i<n;i++){
            freq[items[i][0]]++;
        }
        vector<int>possible(n+1);
        vector<vector<float>>v;
        int ct=0;
        for(int i=1;i<=n;i++){
            if(freq[i]==0)continue;
            ct=0;
            for(int j=i;j<=n;j+=i){
                if(freq[j]==0){
                    continue;
                }
                ct+=freq[j];


            }
            possible[i]=ct-1;
        }
        vector<int>available(n);
        for(int i=0;i<n;i++){
            available[i]=possible[items[i][0]];
            float price=items[i][1];
            v.push_back({price,1,price,(float)i});
            if(available[i]!=0)v.push_back({(price)/2,2,price,(float)i});
            
        }
        sort(v.begin(),v.end(),[](vector<float>&a,vector<float>&b){
            if(a[0]==b[0]){
                if(a[1]==b[1]){

                    return a[2]<b[2];
                }
                return a[1]>b[1];

            }
            return a[0]<b[0];
        });
        for(int i=0;i<available.size();i++){
            // cout<<available[i]<<endl;
        }
        for(int i=0;i<v.size();i++){
            // cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<" "<<v[i][3]<<endl;
        }
        int it=0;
        int ans=0;
        int sz=v.size();
        while(it<sz){
            // cout<<budget<<endl;

            long long power=v[it][1];
            long long price=v[it][2];
            long long ind=v[it][3];
            if(power==2){
                if(price<=budget){
                    long long maxima=available[ind]*price;
                    if(maxima<=budget){
                        ans+=available[ind]*power;
                        budget-=maxima;
                    }
                    else{
                        int can=budget/price;
                        budget-=can*price;
                        ans+=can*power;
                    }

                }
                it++;
            }
            else{
                int can=budget/price;
                // cout<<can;
                ans+=can;
                break;
            }
        }
        return ans;











    }
};