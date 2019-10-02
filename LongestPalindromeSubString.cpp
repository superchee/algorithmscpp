#include <string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int len(s.size());
        if (len <= 1) return s;

        int l(0), r(0);
        int nMax(0), lmax(0);

        for (int i = 0; i < len; i++){
            if (len - i <= nMax / 2) break;
            l = r = i;
            while ( r+1 < len && s[r+1] == s[r]) r++;

            while(l-1>=0 && r+1 < len && s[l-1] == s[r+1]){
                l--;
                r++;
            }

            if(nMax < r-l+1){
                nMax = r-l+1;
                lmax = l;
            }
        }
        return s.substr(lmax, nMax);
    }
};