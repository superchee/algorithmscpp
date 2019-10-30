#include <stdlib.h>
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> map;
    TreeNode* generate(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe){
        if (is>=ie || ps>=pe) return NULL;
        int mid = postorder[pe-1];
        int imidIdx = map[mid];
        int temp = imidIdx-is;
        TreeNode* root = new TreeNode(mid);
        root->left = generate(inorder, is, imidIdx, postorder, ps, ps+temp);
        root->right = generate(inorder, imidIdx+1, ie, postorder, ps+temp, pe-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i < inorder.size();i++){
            map[inorder[i]] = i;
        }
        return generate(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};