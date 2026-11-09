class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();        

        long long ans = 0;
        long long multi = 10;

        int sign = 1;
        int i = 0;

        while(s[i] == ' ')
            i++;

        if(s[i] == '-' || s[i] == '+'){
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        


        for(; i < n; i++){
            if(s[i] >= '0' && s[i] <= '9'){
                ans *= multi;
                ans += (s[i]-'0');
                if(ans * sign < INT_MIN){
                    return INT_MIN;
                }
                if(ans * sign > INT_MAX){
                    return INT_MAX;
                }
                // multi *= 10;
            }
            else{
                cout << s[i] << " break" << endl;
                break; 
            }
        }

        return ans * sign;
    }
};