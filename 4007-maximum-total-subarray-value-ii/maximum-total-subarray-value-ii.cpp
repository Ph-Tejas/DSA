class Solution {
public:
    int n;
    void build1(vector<int>&segTree1,vector<int>& nums,int i,int j,int node){
        int mini=*min_element(nums.begin()+i,nums.begin()+j+1);
        segTree1[node]=mini;
        if(i==j)return;
        int mid=i+(j-i)/2;
        build1(segTree1,nums,i,mid,2*node+1);
        build1(segTree1,nums,mid+1,j,2*node+2);

        

    }
    void build2(vector<int>&segTree2,vector<int>& nums,int i,int j,int node){
        int maxi=*max_element(nums.begin()+i,nums.begin()+j+1);
        segTree2[node]=maxi;
        if(i==j)return;
        int mid=i+(j-i)/2;
        build2(segTree2,nums,i,mid,2*node+1);
        build2(segTree2,nums,mid+1,j,2*node+2);

        

    }
    map<pair<int,int>,int>mp;
    int fun(pair<int,int>range,vector<int>&segTree1,vector<int>&segTree2){
        if(mp.find(range)!=mp.end()){
            return mp[range];
        }
        int i=range.first;
        int j=range.second;
        int mi=INT_MAX,ma=INT_MIN;
        int mini=findMini(i,j,segTree1,0,n-1,0,mi);
        int maxi=findMaxi(i,j,segTree2,0,n-1,0,ma);
        return mp[range]=maxi-mini;

    }
    int findMini(int i,int j,vector<int>&segTree1,int refi,int refj,int node,int &mi){
        if(refj<i || refi>j){
            return mi;
        }
        if(refi==refj){
            return mi=min(mi,segTree1[node]);
        }
        if(refi>=i&&refj<=j){
            return mi=min(segTree1[node],mi);
        }
        int mid=refi+(refj-refi)/2;
        findMini(i,j,segTree1,refi,mid,2*node+1,mi);
        findMini(i,j,segTree1,mid+1,refj,2*node+2,mi);
        

        return mi;
    }
    int findMaxi(int i,int j,vector<int>&segTree2,int refi,int refj,int node,int &ma){
        
        if(refj<i || refi>j){
            return ma;
        }
        if(refi==refj){
            return ma=max(ma,segTree2[node]);
        }
        if(refi>=i&&refj<=j){
            return ma=max(segTree2[node],ma);
        }
        
        int mid=refi+(refj-refi)/2;
        findMaxi(i,j,segTree2,refi,mid,2*node+1,ma);
        findMaxi(i,j,segTree2,mid+1,refj,2*node+2,ma);
        

        return ma;
    }
    long long maxTotalValue(vector<int>& nums, int k) {
        n=nums.size();
        vector<int>segTree1(4*n,INT_MAX);
        vector<int>segTree2(4*n,INT_MIN);
        build1(segTree1,nums,0,n-1,0);
        build2(segTree2,nums,0,n-1,0);
        
        int init=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
        long long ans=0;
        mp[{0,n-1}]=init;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({init,{0,n-1}});
        

        while(k--){
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            ans+=pq.top().first;
            pq.pop();
            if(i==j)break;
            if(i!=j && (mp.find({i+1,j})==mp.end()))pq.push({fun({i+1,j},segTree1,segTree2),{i+1,j}});
            if(i!=j && (mp.find({i,j-1})==mp.end()))pq.push({fun({i,j-1},segTree1,segTree2),{i,j-1}});
            
            



            








        }
        return ans;
        




    }
};