/*
// Definition for a Node.
*/

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};



class Solution {
private:
    unordered_map<Node*, Node*> hash;
    queue<Node*> q;

public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        Node* curNode;

        hash[node] = new Node(node->val, {});

        q.push(node);

        while(!q.empty()){
            curNode = q.front();
            q.pop();
            for(auto neighbor : curNode->neighbors){
                if(hash.find(neighbor) == hash.end()){
                    hash[neighbor] = new Node(neighbor->val, {});
                    q.push(neighbor);
                }
                hash[curNode]->neighbors.push_back(hash[neighbor]);
            }
        }

        return hash[node];
    }
};