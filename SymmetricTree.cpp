#include <stdlib.h>



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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left,q->right) && isSameTree(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        return isSameTree(root->left, root->right);
    }
};