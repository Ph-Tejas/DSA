class Solution {
public:
    int gcd(int a,int b){
        if(b>a){
            int temp=a;
            a=b;
            b=temp;
        }
        if(a%b==0)return b;
        return gcd(b,a%b);



    }
    
    bool areSimilar(vector<vector<int>>& mat, int K) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>lcm;

        vector<int>vis(n); 
        for(int i=1;i<=m;i++){
            if (m%i!=0)continue;
            for(int j=0;j<n;j++){
                if(vis[j]==1)continue;
                vector<int>temp;
                for(int k=0;k<i;k++){
                    temp.push_back(mat[j][k]);
                }
                int it=0;
                for(int k=0;k<m;k++){
                    if(mat[j][k]!=temp[it]){
                        break;

                    }
                    if(k==m-1){
                        lcm.push_back(i);
                        vis[j]=1;
                        
                    }

                    it++;
                    if(it==i)it=0;
                    

                }

            }
        }
        int sz=lcm.size();
        int ans=1;
        
        for(int i=0;i<sz;i++){
            ans=(ans*lcm[i])/gcd(ans,lcm[i]);
        }
        
        if(K%ans==0)return true;
        return false;

    }
};