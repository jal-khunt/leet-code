class Solution {
public:
    static bool comp(vector<int> first, vector<int> second){
        return first[0] < second[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        int n = intervals.size();


        sort(intervals.begin(), intervals.end(), comp);
        vector<int> tmp = intervals[0];

        for(auto it:intervals){
            // cout << it[0] << it[1] << endl;
            if(it[0] <= tmp[1]){
                tmp[1] = max(tmp[1], it[1]);
                // cout << tmp[1] << endl;
            }else{
                merged.push_back(tmp);
                // cout << tmp[0] << tmp[1] << endl;
                tmp = it;
            }
        }
        merged.push_back(tmp);
        // cout << tmp[0] << tmp[1] << endl;

        return merged;
    }
};