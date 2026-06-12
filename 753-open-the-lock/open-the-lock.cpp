class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=1e4;
        vector<int>powy={1,10,100,1000};
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int num=i;
            int ch1=num/powy[3];
            if(ch1==0){
                adj[i].push_back(i+1000);
                adj[i].push_back(i+9000);
            }
            else if(ch1==9){
                adj[i].push_back(i-1000);
                adj[i].push_back(i-9000);
                
            }
            else{
                adj[i].push_back(i-1000);
                adj[i].push_back(i+1000);
            }
            int ch2=(num/powy[2])-(ch1*10);
            if(ch2==0){
                adj[i].push_back(i+100);
                adj[i].push_back(i+900);
            }
            else if(ch2==9){
                adj[i].push_back(i-100);
                adj[i].push_back(i-900);
                
            }
            else{
                adj[i].push_back(i-100);
                adj[i].push_back(i+100);
            }
            int ch3=(num/powy[1])-(ch1*100+ch2*10);
            if(ch3==0){
                adj[i].push_back(i+10);
                adj[i].push_back(i+90);
            }
            else if(ch3==9){
                adj[i].push_back(i-10);
                adj[i].push_back(i-90);
                
            }
            else{
                adj[i].push_back(i-10);
                adj[i].push_back(i+10);
            }
            int ch4=(num/powy[0])-(ch1*1000+ch2*100+ch3*10);
            if(ch4==0){
                adj[i].push_back(i+1);
                adj[i].push_back(i+9);
            }
            else if(ch4==9){
                adj[i].push_back(i-1);
                adj[i].push_back(i-9);
                
            }
            else{
                adj[i].push_back(i-1);
                adj[i].push_back(i+1);
         
            }
        }
        vector<bool>vis(n);
        for(int i=0;i<deadends.size();i++){
            vis[stoi(deadends[i])]=true;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int node=q.front().first;
            int level=q.front().second;

            q.pop();
            if(stoi(target)==node)return level;
            if(vis[node])continue;
            vis[node]=true;
            for(int i=0;i<adj[node].size();i++){
                if(vis[adj[node][i]])continue;
                q.push({adj[node][i],level+1});
            }
        }
        return -1;
    }
};