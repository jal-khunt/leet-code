class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 1){
            return nums[0] == target ? 0 : -1;
        }

        int l = 0, h = n-1;

        while(l <= h){

            // 5 1 3 || t = 3

            int mid = l + (h-l)/2;

            if(nums[mid] == target){
                return mid;
            }

            if(nums[mid] >= nums[l]){
                if(target >= nums[l] && target < nums[mid]){
                    h = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(nums[mid] < target && nums[h] >= target){
                    l = mid + 1;
                }
                else{
                    h = mid;
                }
            }
        }

        return -1;
    }
};