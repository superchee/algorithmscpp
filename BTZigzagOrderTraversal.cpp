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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        TreeNode* tempNode;
        queue<TreeNode*> q;
        int len;
        bool bLeft(true);
        q.push(root);
        while(!q.empty()){
            len = q.size();
            temp.clear();
            for (int i = 0; i < len; i++){
                tempNode = q.front();
                temp.push_back(tempNode->val);
                if(tempNode->left) q.push(tempNode->left);
                if(tempNode->right) q.push(tempNode->right);
                q.pop();
            }
            if (!bLeft) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            bLeft = !bLeft;
        }
        return ans;
    }
};