class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;

            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol])
                    maxRow = i;
            }

            int leftVal  = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol + 1 < m) ? mat[maxRow][midCol + 1] : -1;

            if (mat[maxRow][midCol] > leftVal &&
                mat[maxRow][midCol] > rightVal) {
                return {maxRow, midCol};
            }
            else if (rightVal > mat[maxRow][midCol]) {
                left = midCol + 1;
            }
            else {
                right = midCol - 1;
            }
        }
        return {-1, -1}; 
    }
};