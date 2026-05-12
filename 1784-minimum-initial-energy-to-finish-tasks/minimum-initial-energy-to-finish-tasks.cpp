class Solution {
public:
int n;
    int fun(vector<vector<int>>& tasks,int sum){
        int mini=0;
        int maxi=sum;
        int mid=mini+(maxi-mini)/2;
        while(maxi>=mini){
            int ct=mid;
            bool flag=false;
            for(int i=0;i<n;i++){
                if(ct<tasks[i][1]){
                    flag=true;
                    break;
                }
                ct-=tasks[i][0];
            }
            if(flag){
                mini=mid+1;
            }
            else{
                maxi=mid-1;

            }
            mid=mini+(maxi-mini)/2;
        }
        return mini;
    }
    int minimumEffort(vector<vector<int>>& tasks) {

        n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(tasks[i][1]-tasks[i][0]);
        }
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            
            return a[2]>b[2];
        });
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=tasks[i][1];
        }
        
        return fun(tasks,sum);
    }
};