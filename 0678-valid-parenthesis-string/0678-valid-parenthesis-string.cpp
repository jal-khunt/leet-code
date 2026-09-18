class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();

        int mini = 0, maxi = 0;

        for(char c : s){
            if(c == '('){
                mini += 1;
                maxi += 1;
            }
            else if(c == ')'){
                mini -= 1;
                maxi -= 1;
            }
            else{
                mini -= 1;
                maxi += 1;
            }

            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }

        if(mini == 0)
            return true;

        return false;
    }
};