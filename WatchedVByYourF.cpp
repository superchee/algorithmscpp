#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;



struct Node{
    string s;
    int count;
    Node(){
        s="";
        count = 0;
    }
    };

bool comp(struct Node l, struct Node r){ 
    if(l.count != r.count){
        return l.count < r.count;
    }else{
        return l.s.compare(r.s) < 0;
    }
    } 

class Solution {

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_set<int> sFriend;
        unordered_map<string, int> m;
        queue<int> q;
        sFriend.insert(id);
        q.push(id);
        int nCur(1), nSize, nIdx;
        while(nCur <= level){
            nSize = q.size();
            for(int i = 0; i < nSize; i++){
                nIdx = q.front();
                q.pop();
                for(auto per:friends[nIdx]){
                    if(sFriend.count(per) == 0){
                        sFriend.insert(per);
                        q.push(per);
                    }else{

                    }
                }
            }
            nCur++;
        }

        while(!q.empty()){
            nIdx = q.front();
            q.pop();
            for(auto video: watchedVideos[nIdx]){
                if(m.find(video) == m.end()){
                    m[video] = 1;
                }else{
                    m[video]++;
                }
            }
        }

        struct Node nodeTemp[m.size()];

        int nCount(0);
        for(auto per:m){
            nodeTemp[nCount].s = per.first;
            nodeTemp[nCount].count = per.second;
            nCount++;
        }

        sort(nodeTemp, nodeTemp + m.size(), comp);
        
        vector<string> ans;
        for(int i = 0; i < m.size(); i++){
            ans.push_back(nodeTemp[i].s);
        }


        return ans;

    }
};