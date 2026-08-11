class Solution {
public:

    int solve(int r, int c, vector<vector<int>>& dp, vector<vector<int>>& grid){

        if(r < 0 || c < 0 || grid[r][c])
            return 0;

        if(r == 0 && c == 0)
            return 1;

        if(dp[r][c] != -1){
            return dp[r][c];
        }

        if(grid[r][c])
            return 0;

        dp[r][c] = solve(r,c-1,dp,grid) + solve(r-1,c,dp,grid);

        return dp[r][c];
    }


    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int row = A.size();
        int column = A[0].size();

        if(A[0][0]) return 0;

        vector<vector<int>> dp(row, vector<int>(column,-1));
        return solve(row-1, column-1, dp,A);
    }
};