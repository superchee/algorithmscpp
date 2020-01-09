#include <vector>

using namespace std;



class Solution {

    vector<vector<int>> adj;
    vector<bool> bVisit;
    vector<bool> bRecVisit;

    void Graph(int N, vector<vector<int>>& edges){
        adj.resize(N);

        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
        }
    }

    bool DFS(int v){
        if(!bVisit[v]){
            bVisit[v] = true;
            bRecVisit[v] = true;

            for(auto& per:adj[v]){
                if(!bVisit[per] && DFS(per)){
                    return true;
                }else if(bRecVisit[per]){
                    return true;
                }
            }
        }

        bRecVisit[v] = false;
        return false;
    }



public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph(numCourses, prerequisites);

        bVisit.resize(numCourses,false);
        bRecVisit.resize(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!bVisit[i]){
                if(DFS(i)){
                    return false;
                }
            }
        }

        return true;
    }
};