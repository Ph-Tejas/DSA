class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pf1(n,vector<int>(m));
        int h;
        for(int i=0;i<n;i++){
            h=0;
            for(int j=0;j<m;j++){
                h+=mat[i][j];
                pf1[i][j]=h;
            }
        }
        for(int i=0;i<m;i++){
            h=0;
            for(int j=0;j<n;j++){
                h+=pf1[j][i];
                pf1[j][i]=h;
            }
        }
        int mini=0;
        int maxi=min(m,n);
        int mid=mini+(maxi-mini)/2;
        while(maxi>=mini){
            bool com=false;
            
            for(int i=0;i<n;i++){

                if(com)break;
                for(int j=0;j<m;j++){
                    if(mid==1){
                        if(mat[i][j]<=threshold)com=true;
                    }
                    else{
                        if(i-mid>=-1&&j-mid>=-1){
                            int a,b,c;
                            if(i-mid==-1||j-mid==-1){
                                c=0;
                            }
                            else{
                                c=pf1[i-mid][j-mid];
                            }
                            if(i-mid==-1){
                                a=0;
                            }
                            else{
                                a=pf1[i-mid][j];
                            }
                            if(j-mid==-1){
                                b=0;
                            }
                            else{
                                b=pf1[i][j-mid];
                            }
                            if(pf1[i][j]-(a+b-c)<=threshold)com=true;
                        }
                    }
                    if(com)break;
                    
                }
            }
            if(mid==0)com=true;
            if(com){
                mini=mid+1;
            }
            else maxi=mid-1;
            mid=mini+(maxi-mini)/2;
        }
        return maxi;

        
    }
};