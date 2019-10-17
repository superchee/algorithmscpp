#include <string>
#include <vector>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
    int char2int(char c){
        switch(c){
            case 'A': 
            return 0;
            break;
            case 'C':
            return 1;
            break;
            case 'G':
            return 2;
            break;
            case 'T':
            return 3;
            break;
        }
        return 0;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        bitset<1<<20> set1, set2;
        vector<string> ans;
        int mask = (1<<20) - 1, cstr(0), ss(s.size()), i(0);
        for (;i<9;i++) cstr = cstr<<2 | char2int(s[i]);
        //set1.set(cstr);
        for(; i < ss; i++){
            cstr = cstr<<2 & mask | char2int(s[i]);
            if (set2[cstr]) continue;
            if (set1[cstr]){
                ans.push_back(s.substr(i-9,10));
                set2.set(cstr);
            }else{
                set1.set(cstr);
            }
        }
        return ans;
    }
};


// class Solution {
//     int char2int(char c){
//         switch(c){
//             case 'A': 
//             return 0;
//             break;
//             case 'C':
//             return 1;
//             break;
//             case 'G':
//             return 2;
//             break;
//             case 'T':
//             return 3;
//             break;
//         }
//         return 0;
//     }
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         unordered_map<int, int> ansMap;
//         vector<string> ans;
//         int mask = (1<<20) - 1, cstr(0), ss(s.size()), i(0);
//         for (;i<9;i++) cstr = cstr<<2 | char2int(s[i]);
//         for(; i < ss; i++){
//             if (ansMap[cstr = ((cstr<<2) & mask) | char2int(s[i])]++ == 1){
//                 ans.push_back(s.substr(i-9,10));
//             }
//         }
//         return ans;
//     }
// };