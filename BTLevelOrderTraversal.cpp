#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {


public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        vector<int> temp;
        TreeNode* tempNode;
        int len;
        q.push(root);
        while(!q.empty()){
            len = q.size();
            temp.clear();
            for (int i=0; i < len; i++){
                tempNode = q.front();
                temp.push_back(tempNode->val);
                if (tempNode->left) q.push(tempNode->left);
                if (tempNode->right) q.push(tempNode->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// class Solution {
//     vector<vector<int>> ans;
//     queue<TreeNode*> q;

//     void levelTraversal(queue<TreeNode*> q){
//         queue<TreeNode*> nextq;
//         vector<int> temp;
//         TreeNode* tempNode;
//         if (q.empty()) return;
//         while(!q.empty()){
//             tempNode = q.front();
//             temp.push_back(tempNode->val);
//             if (tempNode->left) nextq.push(tempNode->left);
//             if (tempNode->right) nextq.push(tempNode->right);
//             q.pop();
//         }
//         ans.push_back(temp);
//         levelTraversal(nextq);
//         return;
//     }

// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if (!root) return ans;
//         q.push(root);
//         levelTraversal(q);
//         return ans;
//     }
// };