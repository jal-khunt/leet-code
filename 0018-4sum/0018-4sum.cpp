class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        if(n < 4){
            return {};
        }

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int f = 0; f < n-3; f++){

            if(f > 0 && nums[f] == nums[f-1]){
                continue;
            }
            for(int s = f + 1; s < n-2; s++){

                if(s > f + 1 && nums[s] == nums[s-1]){
                    continue;
                }

                int left = s + 1;
                int right = n - 1;

                while(left < right){
                    long long sum = 0LL + nums[f] + nums[s] + nums[left] + nums[right];

                    if(sum < target){
                        left++;   
                    }
                    else if(sum > target){
                        right--;
                    }
                    else{
                        ans.push_back({nums[f],nums[s],nums[left],nums[right]});

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
        }
        return ans;
    }
};