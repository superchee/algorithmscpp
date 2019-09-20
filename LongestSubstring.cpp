#include <cstring>
#include <unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len(s.size()), nMax(0), start(-1);
        vector<int> idx(256,-1);
        for (int i = 0; i < len; i++){
            if (idx[s[i]] > start){
                start = idx[s[i]];
            }
            idx[s[i]] = i;
            nMax = max(nMax, i-start);
        }

        return nMax;
    }
};

/***
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //unordered_set<char> hashset;
        bool hashtable[256] = {0};
        int start(0), end(0), len(s.size()), nMax = 0;
        while(end < len){
            if (!hashtable[s.at(end)]){
                hashtable[s.at(end++)] = true;
                nMax = max(nMax, end - start);
            }else{
                hashtable[s.at(start++)] = false;
            }
        }
        return nMax;
    }
};
***/