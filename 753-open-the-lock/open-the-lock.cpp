class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=1e4;
        vector<int>powy={1,10,100,1000};
        
        vector<bool>vis(n);
        for(int i=0;i<deadends.size();i++){
            vis[stoi(deadends[i])]=true;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty()){
            int i=q.front().first;
            int level=q.front().second;

            q.pop();
            if(stoi(target)==i)return level;
            if(vis[i])continue;
            vis[i]=true;
            int ch1=i/powy[3];
            if(ch1==0){
                if(!vis[i+1000])q.push({i+1000,level+1});
                if(!vis[i+9000])q.push({i+9000,level+1});
            }
            else if(ch1==9){
                if(!vis[i-1000])q.push({i-1000,level+1});
                if(!vis[i-9000])q.push({i-9000,level+1});
                
            }
            else{
                if(!vis[i-1000])q.push({i-1000,level+1});
                if(!vis[i+1000])q.push({i+1000,level+1});
            }
            int ch2=(i/powy[2])-(ch1*10);
            if(ch2==0){
                if(!vis[i+100])q.push({i+100,level+1});
                if(!vis[i+900])q.push({i+900,level+1});
            }
            else if(ch2==9){
                if(!vis[i-100])q.push({i-100,level+1});
                if(!vis[i-900])q.push({i-900,level+1});
                
            }
            else{
                if(!vis[i-100])q.push({i-100,level+1});
                if(!vis[i+100])q.push({i+100,level+1});
            }
            int ch3=(i/powy[1])-(ch1*100+ch2*10);
            if(ch3==0){
                if(!vis[i+10])q.push({i+10,level+1});
                if(!vis[i+90])q.push({i+90,level+1});
            }
            else if(ch3==9){
                if(!vis[i-10])q.push({i-10,level+1});
                if(!vis[i-90])q.push({i-90,level+1});
                
            }
            else{
                if(!vis[i-10])q.push({i-10,level+1});
                if(!vis[i+10])q.push({i+10,level+1});
            }
            int ch4=(i/powy[0])-(ch1*1000+ch2*100+ch3*10);

            if(ch4==0){
                if(!vis[i+1])q.push({i+1,level+1});  
                if(!vis[i+9])q.push({i+9,level+1});
            }
            else if(ch4==9){
                if(!vis[i-1])q.push({i-1,level+1});
                if(!vis[i-9])q.push({i-9,level+1});                
            }
            else{
                if(!vis[i-1])q.push({i-1,level+1});
                if(!vis[i+1])q.push({i+1,level+1});         
            }
        }
        return -1;
    }
};