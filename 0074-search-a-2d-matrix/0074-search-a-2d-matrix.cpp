class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();

        int l1 = 0, h1 = rows - 1;

        int row = -1;

        while(l1 <= h1){
            int mid = (l1 + h1) / 2;

            if(mat[mid][0] <= target && target <= mat[mid][cols-1]){
                row = mid;
                break;
            }
            else if(target < mat[mid][0]){
                h1 = mid - 1;
            }
            else{
                l1 = mid + 1;
            }
        }

        cout << row << endl;
        if(row == -1){
            return false;
        }
        // int col = -1;

        int l2 = 0, h2 = cols - 1;

        while(l2 <= h2){
            int mid = (l2 + h2) / 2;

            if(mat[row][mid] == target){
                return true;
            }
            else if(mat[row][mid] < target){
                l2 = mid + 1;
            }
            else{
                h2 = mid - 1;
            }
        }

        return false;
    }
};