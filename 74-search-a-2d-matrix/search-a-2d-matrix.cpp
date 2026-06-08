class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=0;
        int maxi=n*m-1;
        int mid=mini+(maxi-mini)/2;

        while(maxi>=mini){
            
            if(matrix[mid/m][mid%m]<target){
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }





            mid=mini+(maxi-mini)/2;
        }
        if(mini==n*m)return false;
        if(matrix[mini/m][mini%m]==target)return true;
        return false;




    }
};