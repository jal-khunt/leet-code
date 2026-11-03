class Solution {
public:

    vector<int> computeRow(int col){
        vector<int> row;

        int res = 1;
        row.push_back(res);

        for(int i = 1; i < col; i++){
            res = res * (col - i);
            res = res / i;

            row.push_back(res);
        }
        return row;
    }

    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        ans.push_back({1});

        for(int row = 2; row <= numRows; row++){
            ans.push_back(computeRow(row));
        }      
        return ans;
    }
};