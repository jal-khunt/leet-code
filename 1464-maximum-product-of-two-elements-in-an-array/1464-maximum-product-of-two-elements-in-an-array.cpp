class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int firstMax = nums[0], secondMax = nums[1];

        if(secondMax > firstMax) swap(firstMax, secondMax);

        for(int i = 2; i < n; i++){
            if(nums[i] > firstMax){
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if(nums[i] > secondMax){
                secondMax = nums[i];
            }
        }

        return (firstMax-1) * (secondMax-1);
    }
};