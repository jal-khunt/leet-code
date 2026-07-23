class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9+7;

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }

        vector<ll> dist(n, 1e12);
        vector<int> ways(n,0);
        ways[0] = 1;
        dist[0] = 0;

        priority_queue< pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll,int>> > pq;

        pq.push({0, 0});

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();

            for(auto &p : adj[node]){
                int adjNode = p.first, adjTime = p.second;
                if(0LL + time + adjTime < dist[adjNode]){
                    dist[adjNode] = time + adjTime;
                    pq.push({dist[adjNode], adjNode});

                    ways[adjNode] = ways[node] % MOD;
                }
                else if(0LL + time + adjTime == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};