class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        // // this is not true because it will also give us value which is greater and smaller
        // auto it1 = lower_bound(nums.begin(), nums.end(), target);
        // int floor = it1 != nums.end() ? it1 - nums.begin() : -1;

        // auto it2 = upper_bound(nums.begin(), nums.end(), target);
        // int ceil = it2 != nums.end() ? it2 - nums.begin() : -1;


        // return {floor, ceil};
        if(n == 0)
            return {-1,-1};

        int first = -1, last = -1;

        int l = 0, r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;


            if(nums[mid] == target){
                first = mid;
                r = mid-1;
            }
            else if(nums[mid] > target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        l = 0, r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                last = mid;
                l = mid + 1;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return {first, last};
    }
};