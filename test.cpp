#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <queue>

#include "helper.h"

#define START "<TEST>"
#define END "<@@@@>"

using namespace std;




int myAtoi(string str);



vector<string> findRepeatedDnaSequences(string s);
bool check(string s1, string s2);
int ladderLength(string beginWord, string endWord, vector<string>& wordList);

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = (char *)realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = (char *)realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return (char *)realloc(str, sizeof(char)*len);
}

int main(){



    vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    //char temp[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
/**
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            board[i][j] = 
        }
    }
    */
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans;

    string str= "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ansVecString;

    //ansVecString = findRepeatedDnaSequences(str);

    string temp, ch("CH");

    temp = START + ch + to_string(2) + END;

    const char* test;
    test = temp.c_str();

    string s1("hit"), s2("cog");

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    int nAns;


    nAns = ladderLength(s1,s2,wordList);


    return 1;
}



    bool check(string s1, string s2){
        int len(s1.size());
        int n(0);
        for (int i=0; i < n; i++){
            if(s1[i] != s2[i]) n++;
        }
        return n==1;
    }

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


