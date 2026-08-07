class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>ans(m);

        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq1;
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>pq2;

        for(int i=0;i<n;i++){
            pq1.push({servers[i],i,0});
        }
        long long t=0;
        for(int i=0;i<m;i++){
            t=max(t,(long long)i);
            if(pq1.empty()){
                t=max(pq2.top()[0],t);
            }
            if(pq2.empty()){
                int ind=pq1.top()[1];
                int strength=pq1.top()[0];
                ans[i]=ind;
                // cout<<i<<" "<<tasks[ind]<<endl;
                pq2.push({t+tasks[i],ind,strength});
                pq1.pop();
            }
            else{
                // cout<<i<<" "<<pq2.top()[0]<<endl;
                while(!pq2.empty() && t>=pq2.top()[0]){
                
                    
                    pq1.push({pq2.top()[2],pq2.top()[1],t});
                    
                    
                    pq2.pop();



                }
                int ind=pq1.top()[1];
                int strength=pq1.top()[0];
                ans[i]=ind;
                pq2.push({t+tasks[i],ind,strength});
                pq1.pop();







            }


        }
        return ans;
























    }
};