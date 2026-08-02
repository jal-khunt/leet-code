class DisjointSet{
    vector<int> size,parent;

public:
    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++){
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

        if(ulp_v == ulp_u) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;
        
        // assign mail to node(row) and if already exist in map then join to its ultimate parent
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // group mails by its parent
        vector<string> mergeMailByParent[n];
        for(auto &it : mapMailNode){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergeMailByParent[node].push_back(mail);
        }

        // structure final output
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mergeMailByParent[i].empty()) continue;

            vector<string> tmp;
            tmp.push_back(accounts[i][0]);

            sort(mergeMailByParent[i].begin(), mergeMailByParent[i].end());

            for(auto &mail : mergeMailByParent[i]){
                tmp.push_back(mail);
            }

            ans.push_back(tmp);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};