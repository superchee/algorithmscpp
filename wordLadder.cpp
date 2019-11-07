#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
    bool check(string s1, string s2){
        int len(s1.size());
        int n(0);
        for (int i=0; i < n; i++){
            if(s1[i] != s2[i]) n++;
        }
        return n==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        unordered_set<string> s;
        queue<string> q;
        string temp;
        int len;
        q.push(beginWord);
        int level(1);
        while(!q.empty()){
            len = q.size();
            for (int i = 0; i < len; i++){
                temp = q.front();
                q.pop();
                for(auto word:wordList){
                    if(s.find(word) != s.end()) continue;
                    if(check(word,temp)){
                        if (word.compare(endWord) == 0) return level+1;
                        q.push(word);
                        s.insert(word);
                    }
                }
            }
            level++;
        }
        return 0;
    }
};