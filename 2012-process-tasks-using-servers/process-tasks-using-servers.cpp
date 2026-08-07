class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>ans(m);

        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>>pq1;
        priority_queue<pair<long long,pair<long long,long long>>,vector<pair<long long,pair<long long,long long>>>,greater<pair<long long,pair<long long,long long>>>>pq2;

        for(int i=0;i<n;i++){
            pq1.push({servers[i],{i,0}});
        }
        long long t=0;
        for(int i=0;i<m;i++){
            t=max(t,(long long)i);
            if(pq1.empty()){
                t=max(pq2.top().first,t);
            }
            if(pq2.empty()){
                int ind=pq1.top().second.first;
                int strength=pq1.top().first;
                ans[i]=ind;
                // cout<<i<<" "<<tasks[ind]<<endl;
                pq2.push({t+tasks[i],{ind,strength}});
                pq1.pop();
            }
            else{
                // cout<<i<<" "<<pq2.top().first<<endl;
                while(!pq2.empty() && t>=pq2.top().first){
                
                    
                    pq1.push({pq2.top().second.second,{pq2.top().second.first,t}});
                    
                    
                    pq2.pop();



                }
                int ind=pq1.top().second.first;
                int strength=pq1.top().first;
                ans[i]=ind;
                pq2.push({t+tasks[i],{ind,strength}});
                pq1.pop();







            }


        }
        return ans;
























    }
};