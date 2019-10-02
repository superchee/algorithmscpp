#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len(INT_MAX), lenVec(strs.size()), maxLen(0);
        if (lenVec == 0) return "";
        for (int i = 0; i < lenVec; i++){
            len = min((int)strs[i].size(), len);
        }
        for (int i = 0; i < len; i++){
            for (int j = 1; j < lenVec; j++){
                if(strs[j-1][i] != strs[j][i]){
                    return strs[0].substr(0,maxLen);
                }
            }
            maxLen++;
        }
        return strs[0].substr(0, maxLen);
    }
};