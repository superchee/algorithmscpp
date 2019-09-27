#include <limits>
#include <cmath>

class Solution {
    bool isValid(int a, int b){
        if (a > 0){
            return a < INT_MAX - b;
        }else{
            return a > INT_MIN - b;
        }
    }
public:
    int reverse(int x) {
        if (x == INT_MIN || x == 0) return 0;
        int ans(0);

        while(x){
            if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
            if (!isValid(ans*10, x%10)) return 0;
            ans = ans*10 + x%10;
            x = x/10;
        }

        return ans;

    }
};