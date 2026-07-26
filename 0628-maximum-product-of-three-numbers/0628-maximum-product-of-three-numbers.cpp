class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int num1 = nums[n-1] * nums[n-2] * nums[n-3];
        int num2 = nums[0] * nums[1] * nums[n-1];

        cout << num1 << num2 << endl;

        return num1 > num2 ? num1 : num2;
    }
};