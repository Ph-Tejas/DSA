class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int sz=meetings.size();
        
        vector<int>ans(n);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        priority_queue<int,vector<int>,greater<int>>vacant;

        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++){
            vacant.push(i);
        }
        
        for(int it=0;it<sz;it++){
            long long a=meetings[it][0];
            long long b=meetings[it][1];
            while(!pq.empty() && a>=pq.top().first){
                int loc=pq.top().second;
                long long en=pq.top().first;
                
                
                pq.pop();
                vacant.push(loc);

            

            }
            if(!vacant.empty()){
                int loc=vacant.top();
                vacant.pop();
                pq.push({b,loc});
                ans[loc]++;
                
                continue;
                
            }
            if(it==sz)break;
            if(!pq.empty()){
                int loc=pq.top().second;
                long long en=pq.top().first;

                
                pq.pop();
                
                pq.push({b+en-a,loc});
                ans[loc]++;
                


                
            }



        }
        int maxi=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(maxi<ans[i]){
                ind=i;
                maxi=ans[i];
            }
        }
        return ind;
        
        









    }
};