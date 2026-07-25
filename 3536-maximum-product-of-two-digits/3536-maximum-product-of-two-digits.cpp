class Solution {
public:
    int maxProduct(int n) {
        int first = n % 10;
        n /= 10;
        int second = n % 10;
        n /= 10;

        if(second > first) swap(first, second);

        while(n){
            int a = n % 10;
            n /= 10;

            // cout << a << first << second << endl;
            if(a > first){
                second = first;
                first = a;
            }
            else if(a > second){
                second = a;
            }
        }


        return first * second;
    }
};