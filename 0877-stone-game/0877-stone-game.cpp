class Solution {
public:
    
    int t[503][503];

    int helper(int i, int j, vector<int> &piles){
        if(i > j) return 0;
        if(i == j) return piles[i];

        if(t[i][j] != -1)
            return t[i][j];

        int take_i = piles[i] + min( helper(i+2,j, piles), helper(i+1, j-1, piles) );
        int take_j = piles[j] + min( helper(i,j-2, piles), helper(i+1, j-1, piles) );

        return t[i][j] =  max(take_i,take_j);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(t, -1, sizeof(t));

        int total_stones = 0;
        for(auto &pile : piles){
            total_stones += pile;
        }

        int alice_score = helper(0, n-1, piles);
        int bob_score = total_stones - alice_score;

        return alice_score > bob_score;
    }
};