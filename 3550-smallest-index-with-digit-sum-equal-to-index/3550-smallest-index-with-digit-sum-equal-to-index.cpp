class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int n = nums.size();


        for(int i = 0; i < n; i++){
            int num = nums[i];
            int f = num%10;
            num /= 10;
            int s = num%10;
            num/=10;
            int t = num%10;
            num/=10;
            int l = num%10;

            if(i == f+s+t+l){
                return i;
            }
        }
        return -1;
    }
};