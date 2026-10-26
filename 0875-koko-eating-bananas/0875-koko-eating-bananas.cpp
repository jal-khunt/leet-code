class Solution {
public:

    int findMaximum(vector<int>& arr){
        int maxi = INT_MIN;
        for(int i : arr){
            maxi = max(maxi, i);
        }
        return maxi;
    }

    long long findHours(vector<int>& arr, int bananas){
        int n = arr.size();
        long long totalHours = 0;
        for(int i = 0; i < n; i++){
            totalHours += ceil((double)arr[i] / (double)bananas);
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() == 1 && piles[0] <= h){
            return 1;
        }

        int low = 1;
        int high = findMaximum(piles);


        while(low <= high){
            int mid = (low + high) / 2;

            long long totalHours = findHours(piles, mid);

            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};