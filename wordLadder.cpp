#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if (!s.count(endWord)) return 0;
        unordered_set<string> w1, w2, temp;
        int len(beginWord.size());
        int level(2);
        char c;

        w1.insert(beginWord);
        w2.insert(endWord);

        while(!w1.empty()&&!w2.empty()){
            if(w1.size() > w2.size()) swap(w1,w2);
            temp.clear();
            for(auto word:w1){
                for(int i = 0; i < len; i++){
                    c = word[i];
                    for(int j = 0; j < 26; j++){
                        word[i] = j+'a';
                        if(w2.count(word)) return level;
                        if(s.count(word)){
                            temp.insert(word);
                            s.erase(word);
                        }
                    }
                    word[i] = c;
                }
            }
            swap(w1,temp);
            level++;
        }
        return 0;
    }
};

// class Solution {
//     bool check(string s1, string s2){
//         int len(s1.size());
//         int n(0);
//         for (int i=0; i < len; i++){
//             if(s1[i] != s2[i]) n++;
//         }
//         return n==1;
//     }
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
//         unordered_set<string> s;
//         queue<string> q;
//         string temp;
//         int len;
//         for(auto word:wordList){
//             s.insert(word);
//         }
//         q.push(beginWord);
//         int level(1);
//         while(!q.empty()){
//             len = q.size();
//             for (int i = 0; i < len; i++){
//                 temp = q.front();
//                 q.pop();
//                 for(auto it = s.begin();it!=s.end();){
//                     if(check(*it,temp)){
//                         if ((*it).compare(endWord) == 0) return level+1;
//                         q.push(*it);
//                         it = s.erase(it);
//                     }else{
//                         it++;
//                     }
//                 }
//             }
//             level++;
//         }
//         return 0;
//     }
// };