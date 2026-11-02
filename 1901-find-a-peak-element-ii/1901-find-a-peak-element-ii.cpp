class Solution {
public:

    int findMax(vector<vector<int>>& mat, int col, int rows){
        int index  = 0;
        int maxEl = mat[0][col];

        for(int i = 1; i < rows; i++){
            if(mat[i][col] > maxEl){
                maxEl = mat[i][col];
                index = i;
            }
        }

        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0, high = cols-1;

        while(low <= high){
            int mid = (low + high) / 2;

            int row = findMax(mat, mid, rows);

            int left = (mid == 0) ? -1 : mat[row][mid-1];
            int right = (mid == cols-1) ? -1 : mat[row][mid+1];

            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(left > mat[row][mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return {-1,-1};
    }
};