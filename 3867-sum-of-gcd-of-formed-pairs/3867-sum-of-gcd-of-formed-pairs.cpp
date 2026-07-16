class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        vector<int> prefixGcd(n,0);
        prefixGcd[0] = __gcd(maxi, nums[0]);

        for(int i = 1; i < n; i++){
            maxi = max(maxi, nums[i]);
            prefixGcd[i] = __gcd(maxi, nums[i]);
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        int i = 0, j = n-1;

        long long ans = 0;

        while(i < j){
            ans += __gcd(prefixGcd[i], prefixGcd[j]);

            i++;
            j--;
        }

        return ans;
    }
};