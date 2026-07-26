class Solution {
public:

    int numberOfreachCities(int node, int n, vector<vector<pair<int,int>>> &adj, int threshold){
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, node});
        dist[node] = 0;

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d > dist[u]) continue;

            for(auto &p : adj[u]){
                int v = p.first, wt = p.second;

                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int cities = 0;

        for(int i = 0; i < n; i++){
            if(i != node && dist[i] <= threshold){
                cities++;
            }
        }

        return cities;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int minReachable = INT_MAX;
        int bestCity = -1;

        for(int i = 0; i < n; i++){
            int reachableCities = numberOfreachCities(i, n, adj, distanceThreshold);

            if(reachableCities <= minReachable){
                minReachable = reachableCities;
                bestCity = i;
            }
        }

        return bestCity;
    }
};