class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>pr;
        int n=position.size();
        for(int i=0;i<n;i++){
            pr.push_back({position[i],speed[i]});
        }
        sort(pr.begin(),pr.end());
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int i=0;i<n;i++){
            double curr=((double)target-pr[i].first)/pr[i].second;
            while(!pq.empty() && pq.top()<=curr)pq.pop();
            pq.push(curr);
        }
        return pq.size();
    }
};