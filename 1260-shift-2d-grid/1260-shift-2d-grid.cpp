class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(!k) return grid;

        int r = grid.size();
        int c = grid[0].size();
        int total = r * c;
        k = k % total;

        vector<vector<int>> ans(r, vector<int>(c,0));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int old_idx = (i*c)+j;

                int new_idx = (old_idx + k) % total;

                int nr = new_idx / c, nc = new_idx % c;

                ans[nr][nc] = grid[i][j];
            }
        }

        return ans;
    }
};