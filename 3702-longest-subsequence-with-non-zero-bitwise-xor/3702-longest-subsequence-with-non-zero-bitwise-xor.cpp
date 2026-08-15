class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int total = 0;
        bool allZero = true;

        for(auto x : nums){
            total ^= x;
            if(x > 0){
                allZero = false;
            }
        }

        if(total > 0){
            return n;
        }

        return allZero ? 0 : n-1;
    }
};