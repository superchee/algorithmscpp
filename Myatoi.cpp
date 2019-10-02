#include <string>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        int Idx(0), sign(1), ans(0), temp(0);

        while(str[Idx] == ' ') Idx++;

        if (str[Idx] == '+'){
            sign = 1;
            Idx++;
        }else if(str[Idx] == '-'){
            sign = -1;
            Idx++;
        }

        while(str[Idx] <= '9' && str[Idx] >= '0'){
            temp = str[Idx] - '0';
            if (ans > (INT_MAX - temp)/10) return sign > 0? INT_MAX:INT_MIN;
            ans = ans*10 + temp;
        }

        return ans*sign;

    }

};