#include <string>

using namespace std;

class Solution {
    
public:
    int strStr(string haystack, string needle) {
        int len1(haystack.size()), len2(needle.size());
        bool check(true);
        if (len2 == 0) return 0;

        for (int i = 0; i <= len1-len2; i++){
            if (haystack[i] == needle[0]){
                check = true;
                for (int j = 1; j < len2; j++){
                    if (haystack[i+j] != needle[j]){
                        check = false;
                    }
                }
                if(check) return i; 
            }
        }
        return -1;
    }
};