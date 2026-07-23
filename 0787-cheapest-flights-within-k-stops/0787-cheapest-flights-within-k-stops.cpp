class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            adj[u].push_back({v, wt});

            // cout << u << v << wt << endl;
        }

        // {stop, {node, price}}
        queue<pair<int, pair<int,int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});

        while(!q.empty()){
            int stops = q.front().first;
            int curr = q.front().second.first;
            int price = q.front().second.second;
            q.pop();

            // cout << stops << " " << curr << " " << price << endl;

            if(stops > k) continue;

            for(auto &p : adj[curr]){
                int v = p.first, wt = p.second;
                // cout << v << " " <<  wt << endl;
                // cout << price << " " << wt << " " << (price + wt) << dist[v] << endl;
                if(price + wt < dist[v] && stops <= k){
                    dist[v] = price + wt;
                    q.push({stops+1, {v, dist[v]}});
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;

        return dist[dst];
        

    }
};