#include <vector>
#include <stdlib.h>

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
    vector<TreeNode*> generator(int s, int e){
        vector<TreeNode*> res;
        if (s >= e){
            res.push_back(NULL);
            return res;
        } 

        for (int i = s; i <e; i++){
            vector<TreeNode*> leftTree = generator(s,i);
            vector<TreeNode*> rightTree = generator(i+1,e);

            for (auto left:leftTree){
                for (auto right:rightTree){
                    TreeNode* node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    res.push_back(node);
                }
            }
        }

        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {

        if (n==0){
            vector<TreeNode*> res;
            return res;
        }
        return generator(1,n+1);
    }
};