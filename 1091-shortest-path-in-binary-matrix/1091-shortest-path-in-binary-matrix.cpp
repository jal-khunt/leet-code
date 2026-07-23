class Solution {
public:

    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,1}, {-1,-1}, {1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1) return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        dist[0][0] = 1;
        pq.push({1, {0,0}});

        while(!pq.empty()){
            auto [d, idx] = pq.top();
            pq.pop();

            int i = idx.first, j = idx.second;

            for(auto &dir:directions){
                int ni = i + dir[0], nj = j + dir[1];

                if(ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0 && d + 1 < dist[ni][nj]){
                    dist[ni][nj] = d + 1;
                    pq.push({dist[ni][nj], {ni,nj}});
                }
            } 
        }

        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};