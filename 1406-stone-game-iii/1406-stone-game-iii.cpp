class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> t(n+1, 0);

        for(int i = n-1; i >= 0; i--){
            t[i] = stones[i] - t[i+1];

            if(i+2 <= n)
                t[i] = max(t[i], stones[i] + stones[i+1] - t[i+2]);

            if(i+3 <= n)
                t[i] = max(t[i], stones[i] + stones[i+1] + stones[i+2] - t[i+3]);
        }


        if(t[0] > 0)
            return "Alice";
        else if(t[0] < 0)
            return "Bob";

        return "Tie";
    }
};