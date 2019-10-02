class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;


        int temp(x);
        long ans(0);

        while(x){
            ans = ans*10 + x%10;
            x = x/10;
        }
        return (int)ans == temp;

    }
};