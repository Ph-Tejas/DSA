class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double min=0;
        double max=1e9+1;
        double mid=min+(max-min)/2;
        int n=squares.size();
        double tot=0;
        for(int i=0;i<n;i++){
            long long a=squares[i][2];
            tot+=a*a;
        }
        tot/=2;
        double dd=0.000001;
        while(max>=min){
            double sum=0;
            for(int i=0;i<n;i++){
                long long a=squares[i][2];
                long long b=squares[i][1];
                if(b>=mid)sum+=a*a;
                else{
                    if(b+a>mid){
                        sum+=a*(b+a-mid);
                    }
                }
            }
            if(sum<=tot){
                max=mid-dd;
            }
        
            else{
                min=mid+dd;
            }
            mid=min+(max-min)/2;
        }
        return min;
    }
};