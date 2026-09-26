class Solution {
public:
    int mySqrt(int x) {

        if(x == 0)
            return 0;
        
        int l =1, h = x/2;
        int result = 1;

        while(l <= h){
            long long mid = l + (h-l)/2;

            long long tmp = mid*mid;
            if(tmp == x){
                return mid;
            }

            if(tmp <= x){
                result = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return result;
    }
};