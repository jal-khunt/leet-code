class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxFreq = n / 3;

        unordered_map<int,int> freq;
        unordered_set<int> ans;

        for(int i = 0; i < n; i++){
            if(freq[nums[i]] < maxFreq){
                freq[nums[i]]++;
            }
            else{
                ans.insert(nums[i]);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};