class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
        if(n1.size() > n2.size()){
            return findMedianSortedArrays(n2, n1);
        }

        int n = n1.size();
        int m = n2.size();

        if(n == 0){

        }

        int leftSide = (n+m+1) / 2;

        int low = 0, high = n;

        while(low <= high){
            int mid = (low+high)/2;
            int mid2 = leftSide - mid;

            int l1 = (mid == 0) ? INT_MIN : n1[mid-1];
            int r1 = (mid == n) ? INT_MAX : n1[mid];

            int l2 = (mid2 == 0) ? INT_MIN : n2[mid2-1];
            int r2 = (mid2 == m) ? INT_MAX : n2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((n+m)%2 == 1){
                    return max(l1,l2);
                }
                else{
                    return (double)(max(l1,l2)+min(r1,r2)) / 2.0;
                }
            }
            else if(l1 > r2){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return 0.0;
    }
};