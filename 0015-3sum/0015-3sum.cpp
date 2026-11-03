class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return {};
        }

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int f = 0; f < n-2; f++){

            if(f > 0 && nums[f] == nums[f-1]){
                continue;
            }

            int left = f + 1;
            int right = n - 1;

            while(left < right){
                long long sum = 1LL * nums[f] + nums[left] + nums[right];

                if(sum < 0){
                    left++;
                }
                else if(sum > 0){
                    right--;
                }
                else{
                    ans.push_back({nums[f],nums[left],nums[right]});

                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }

                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};