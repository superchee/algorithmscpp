#include <stdlib.h>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        if (root == NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* cur(root);

        while(cur || s.size()){
            if (cur){
                s.push(cur);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        

        return ans;
    }
};

// class Solution {
//     vector<int> ans;
//     void Traversal(TreeNode* root){
//         if (root == NULL) return;

//         Traversal(root->left);

//         ans.push_back(root->val);

//         Traversal(root->right);

//         return;
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {

//         Traversal(root);

//         return ans;
//     }
// };