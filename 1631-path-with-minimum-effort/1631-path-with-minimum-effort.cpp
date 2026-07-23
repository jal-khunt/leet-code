class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<vector<int>> dist(r, vector<int>(c, 1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto [diff , idx] = pq.top();
            pq.pop();
            int i = idx.first, j = idx.second;

            if(i == r-1 && j == c-1){
                return diff;
            }

            for(auto &dir : directions){
                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni >= 0 && ni < r && nj >= 0 && nj < c){
                    int newEffort = max(diff, abs(heights[i][j] - heights[ni][nj]));

                    if(newEffort < dist[ni][nj]){
                        dist[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }

        return 0;
    }
};