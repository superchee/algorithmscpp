#include <stdlib.h>
#include <algorithm>

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
    int maxAns;
    int depth(TreeNode* root){
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return depth(root);
    }
};


// class Solution {
//     int maxAns;
//     void travel(TreeNode* root, int n){
//         if (root == NULL){
//             maxAns = max(maxAns, n-1);
//             return;
//         }
//         travel(root->left,n+1);
//         travel(root->right,n+1);
//     }
// public:
//     int maxDepth(TreeNode* root) {
//         maxAns = 0;
//         travel(root,1);
//         return maxAns;
//     }
// };

