class Solution {
public:

    bool possible(vector<int>& arr, int weight, int days){
        int n = arr.size();
        int sum = 0, cnt = 0;

        for(int i = 0; i < n; i++){

            if(sum + arr[i] <= weight){
                sum += arr[i];
            }
            else{
                sum = arr[i];
                cnt += 1;
            }
        }

        if(sum <= weight) cnt += 1;

        return cnt <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0;

        int n = weights.size();

        for(int i : weights){
            low = max(low, i);
            high += i;
        }

        while(low <= high){
            int mid = (low+high)/2;

            if(possible(weights, mid, days)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};