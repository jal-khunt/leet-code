class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;

        int i = 0, j = 0, ans = 0;

        while(j < n){
            if(mp[nums[j]] == k){
                mp[nums[i]]--;   
                i++;
            }
            else{
                mp[nums[j]]++;
                ans = max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};