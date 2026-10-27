class Solution {
public:

    bool possible(int day, vector<int>& arr, int m, int k){
        int cnt = 0, noOfB = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            if(arr[i] <= day){
                cnt++;
            }
            else{
                noOfB += (cnt/k);
                cnt = 0;
            }
        }
        noOfB += (cnt/k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        int n = bloomDay.size();

        if(n < (long long)m*k)
            return -1;

        for(int i : bloomDay){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        while(mini <= maxi){
            int mid = (mini+maxi) / 2;

            if(possible(mid, bloomDay, m, k)){
                maxi = mid - 1;
            }
            else{
                mini = mid + 1;
            }
        }

        return mini;
    }
};