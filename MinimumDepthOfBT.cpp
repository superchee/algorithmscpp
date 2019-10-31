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
    int minDepth(TreeNode* root) {
        int level(0);
        if (!root) return level;
        queue<TreeNode*> q;
        TreeNode* temp;
        bool bFind(false);
        int len(0);
        q.push(root);
        level++;
        while(!q.empty()){
            len = q.size();
            for(int i = 0; i < len; i++){
                temp = q.front();
                if (!temp->left && !temp->right){
                    return level;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                q.pop();
            }
            level++;
        }
        return level;
    }
};

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         if(!root)   return 0;
//         if(!root->left) return (1 + minDepth(root->right)); 
//         if(!root->right)    return (1 + minDepth(root->left));
//         return 1 + min(minDepth(root->right), minDepth(root->left));
//     }
// };