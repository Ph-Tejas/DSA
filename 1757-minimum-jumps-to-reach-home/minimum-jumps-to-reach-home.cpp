class Solution {
public:
    set<int>st;
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int n=forbidden.size();
        vector<int>vis(41001);
        for(int i=0;i<n;i++){
            vis[forbidden[i]]=1;
        }
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        while(!q.empty()){
            int ind=q.front().first;
            int turn=q.front().second.first;

            int com=q.front().second.second; 

            q.pop();
            if(vis[ind]==1)continue;
            if(x==ind)return turn;
            vis[ind]=1;
            if(ind-b>=0&&com==0){
                q.push({ind-b,{turn+1,1}});
            }
            if(ind+a<=41000){
                q.push({ind+a,{turn+1,0}});
            }

            

        }
        return -1;


    }
};