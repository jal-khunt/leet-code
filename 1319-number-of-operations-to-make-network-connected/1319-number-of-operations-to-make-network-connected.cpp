class DisjointSet{
    vector<int> rank,parent;
    vector<long long> size;
 public:
    int extraEdge = 0;
    DisjointSet(int n){
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if(node == parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) extraEdge++;
        // cout << u << "---" << v << endl;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if(ulp_u == ulp_v) extraEdge++;
        // cout << u << "---" << v << endl;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int getNumberOfComponents(int n){
        int numberOfComponents = 0;
        for(int i = 0; i <= n; i++){
            if(i == parent[i])
                numberOfComponents++;
        }
        return numberOfComponents;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        for(auto &connection : connections){
            ds.unionByRank(connection[0], connection[1]);
        }

        int components = ds.getNumberOfComponents(n) - 1; // -1 because we here 0 base index network and in class there is 1 base index 

        // cout << "extraEdge : " << ds.extraEdge << " Components : " << components << endl;
        
        // we need minimum total (components - 1) edge to connect network
        if(ds.extraEdge >= components-1)
            return components - 1;
        
        return -1;
    }
};