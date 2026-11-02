class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();
        // cout << rows << cols << endl;

        if(target > mat[rows-1][cols-1]) return false;

        int row = 0, col = cols-1;
        // cout << row << col << endl;

        while(row < rows && col >= 0){
            if(mat[row][col] == target){
                return true;
            }
            else if(target <mat[row][col]){
                col--;
            }
            else{
                row++;
            }
        }

        return false;
    }
};