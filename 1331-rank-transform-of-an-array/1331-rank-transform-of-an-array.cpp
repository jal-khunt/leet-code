class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> tmp(arr);

        sort(tmp.begin(), tmp.end());

        int rank = 1;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            if(i > 0 && tmp[i] > tmp[i-1])
                rank++;

            mp[tmp[i]] = rank;
        }

        vector<int> result(n, 0);

        for(int i = 0; i < n; i++){
            result[i] = mp[arr[i]];
        }

        return result;
    }
};