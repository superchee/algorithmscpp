#include <stdlib.h>
#include <algorithms>
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root, pre(NULL);
        while (cur || !s.empty()){
            if(cur){
                s.push_back(cur);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                if (pre && pre->val >= cur->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};


//  class Solution {
//      vector<int> s;
//     void inOrder(TreeNode* root){
//         if (root == NULL) return;
//         inOrder(root->left);
//         s.push_back(root->val);
//         inOrder(root->right);
//         return;
//     }

// public:
//     bool isValidBST(TreeNode* root) {
//         inOrder(root);
//         for(int i =1; i < s.size(); i++){
//             if (s[i] <= s[i-1]) return false;
//         }
//         return true;
//     }
// };
 
// class Solution {

//     bool isValid(TreeNode* root, TreeNode* &pre){
//         if (root == NULL) return true;
//         if (!isValid(root->left, pre)) return false;
//         if (pre && root->val <= pre->val) return false;
//         pre = root;
//         return isValid(root->right, pre);
//     }

// public:
//     bool isValidBST(TreeNode* root) {
//         TreeNode* pre(NULL);
//         return isValid(root, pre);
//     }
// };