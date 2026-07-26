class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = -1001, max2 = max1, max3 = max1;
        int min1 = 1001, min2 = min1;

        for(auto &num : nums){
            int partial_max1 = max1, partial_max2 = max2, partial_min1 = min1;

            max1 = max(max1, num);
            max2 = max(max2, min(partial_max1, num));
            max3 = max(max3, min(partial_max2, num));


            min1 = min(min1, num);
            min2 = min(min2, max(partial_min1, num));
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};