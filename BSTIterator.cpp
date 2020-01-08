/*
 * Definition for a binary tree node.
 */

#include <cstdlib>
#include <stack>
#include <vector>


using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {

    stack<TreeNode*> s;

public:
    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ans = s.top();
        int ret = ans->val;
        s.pop();
        ans = ans->right;
        while(ans!=nullptr){
            s.push(ans);
            ans = ans->left;
        }
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};



// class BSTIterator {
//     int m_nIdx;
//     vector<int> m_Value;

// public:
//     BSTIterator(TreeNode* root) {
//         stack<TreeNode*> s;
//         TreeNode* pCur(root);
//         m_Value.clear();
//         while(!s.empty() || pCur!=nullptr){
//             if(pCur!=nullptr){
//                 s.push(pCur);
//                 pCur = pCur->left;
//             }else{
//                 pCur = s.top();
//                 s.pop();
//                 m_Value.push_back(pCur->val);
//                 pCur = pCur->right;
//             }
//         }
//         m_nIdx = -1;
//     }
    
//     /** @return the next smallest number */
//     int next() {
//         return m_Value[++m_nIdx];
//     }
    
//     /** @return whether we have a next smallest number */
//     bool hasNext() {
//         return m_nIdx + 1 < m_Value.size();
//     }
// };
