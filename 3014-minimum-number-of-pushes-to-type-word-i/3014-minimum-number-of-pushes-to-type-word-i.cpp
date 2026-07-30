class Solution {
public:
    int minimumPushes(string word) {

        int n = word.size();
        if(n <= 8) return n;

        int full = n / 8;
        int reminder = n % 8;
        
        long long i = 1;
        long long ans = 0;
        while(i <= full){
            ans = ans + (i*8);
            i++;
        }

        ans += (i*reminder);

        return ans;
    }
};