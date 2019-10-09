#include <string>
#include <vector>

using namespace std;

class Solution{
    public:
        bool isMatch(string s, string p){
            int nS(s.size()), nP(p.size()), sIdx(0), pIdx(0), ss(0), ps(-1);

            while(sIdx < nS){
                if (pIdx < nP && (s[sIdx] == p[pIdx] || p[pIdx] == '?')){
                    sIdx++;
                    pIdx++;
                    continue;
                }
                if (pIdx < nP && p[pIdx] == '*'){
                    ps = pIdx;
                    pIdx++;
                    ss = sIdx;
                    continue;
                }
                if (ps < nP && ps != -1){
                    sIdx = ++ss;
                    pIdx = ps+1;
                    continue;
                }
                return false;
            }
            while(pIdx < nP ){
                if (p[pIdx] != '*') return false;
                pIdx++;
            }

            return true;
        }
};





// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int nS(s.size()), nP(p.size());

//         vector<vector<bool>> match(nS+1,vector<bool>(nP+1,false));
//         match[0][0] = true;

//         for (int i = 0; i < nS+1; i++){
//             for (int j = 1; j < nP+1; j++){
//                 if(p[j-1] == '*'){
//                     match[i][j] = match[i][j-1] || (i && match[i-1][j-1]);
//                 }else{
//                     match[i][j] = i && match[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
//                 }
//             }
//         }

//         return match[nS][nP];
//     }
// };