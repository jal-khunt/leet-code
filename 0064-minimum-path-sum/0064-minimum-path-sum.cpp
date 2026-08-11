class Solution {
public:
    int r,c;

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& t){
        if(i == 0 && j == 0)    return grid[0][0];

        if(i < 0 || j < 0) return INT_MAX;

        if(t[i][j] != -1) return t[i][j];

        t[i][j] = grid[i][j] + min(solve(i-1, j, grid, t), solve(i, j-1, grid, t));

        return t[i][j];
    }


    int minPathSum(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        vector<vector<int>> t(r, vector<int> (c,-1));

        return solve(r-1, c-1, grid, t);
    }
};