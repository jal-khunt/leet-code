class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return n;

        int mask = 1;
        while(mask <= n){
            mask *= 2;
        }

        return mask;
    }
};