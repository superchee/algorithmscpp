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
    TreeNode* generate(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
        if (is>ie || ps>pe) return NULL;
        int mid = preorder[ps];
        //vector<int>::iterator itr = find(inorder.begin()+is, inorder.begin()+ie, mid);
        int imidIdx = map[mid];
        TreeNode* root = new TreeNode(mid);
        root->left = generate(preorder, ps+1, ps+imidIdx-is, inorder, is, imidIdx-1);
        root->right = generate(preorder, ps+imidIdx-is+1, pe, inorder, imidIdx+1, ie);
        return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return generate(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

// class Solution {
//     TreeNode* generate(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie){
//         if (is>=ie || ps>=pe) return NULL;
//         int mid = preorder[ps];
//         vector<int>::iterator itr = find(inorder.begin()+is, inorder.begin()+ie, mid);
//         int ndis = itr - inorder.begin() - is;
//         TreeNode* root = new TreeNode(mid);
//         root->left = generate(preorder, ps+1, ps+ndis+1, inorder, is, is+ndis);
//         root->right = generate(preorder, ps+ndis+1, pe, inorder, is+ndis+1, ie);
//         return root;

//     }
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return generate(preorder, 0, preorder.size(), inorder, 0, inorder.size());
//     }
// };