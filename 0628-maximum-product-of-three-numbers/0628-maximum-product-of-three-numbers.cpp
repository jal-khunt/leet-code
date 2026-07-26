class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int firstMax = -1001, secondMax = -1001, thirdMax = -1001;
        int firstMin = 1001, secondMin = 1001;

        for(auto &num : nums){
            if(num > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            else if(num > secondMax){
                thirdMax = secondMax;
                secondMax = num;
            }
            else if(num > thirdMax){
                thirdMax = num;
            }

            if(num < firstMin){
                secondMin = firstMin;
                firstMin = num;
            }
            else if(num < secondMin){
                secondMin = num;
            }
        }

        return max(firstMax*secondMax * thirdMax, firstMin * secondMin * firstMax);
    }
};