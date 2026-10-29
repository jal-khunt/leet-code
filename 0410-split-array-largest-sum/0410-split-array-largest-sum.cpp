class Solution {
public:

    int findParts(vector<int> &nums, int maxSum){
        int parts = 1;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                parts += 1;
                sum = nums[i];
            }
        }

        // if(sum <= maxSum) parts += 1;

        return parts;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n) return -1;

        int low = INT_MIN;
        int high = 0;

        for(int i : nums){
            low = max(low, i);
            high += i;
        }

        while(low <= high){
            int mid = (low + high) / 2;

            int parts = findParts(nums, mid);

            if(parts > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return low;
    }
};