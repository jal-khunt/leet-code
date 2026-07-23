class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &t : times){
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n+1, 1e9);
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        dist[k] = 0;
        pq.push({0,k});


        while(!pq.empty()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // min_time = min()

            for(auto &p : adj[node]){
                int v = p.first, t2 = p.second;
                if(time + t2 < dist[v]){
                    dist[v] = time + t2;
                    pq.push({dist[v], v});
                }
            }
        }

        int min_time = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            min_time = max(min_time, dist[i]);
        }

        return min_time;
    }
};