class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        int l = 0, h = n-1;

        int minimum = 5001;

        while(l <= h){
            int mid = l + (h-l)/2;

            if(nums[l] <= nums[mid]){
                minimum = min(minimum, nums[l]);
                l = mid + 1;
            }
            else{
                minimum = min(minimum, nums[mid]);
                h = mid - 1;
            }
        }

        return minimum;
    }
};