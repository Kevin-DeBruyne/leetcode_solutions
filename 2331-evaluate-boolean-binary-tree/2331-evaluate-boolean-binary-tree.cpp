/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        bool l=evaluateTree(root->left);
        bool r=evaluateTree(root->right);
        if(root->val==2)
            return l || r;
        if(root->val==3)
            return l and r;
        return root->val;
            
    }
};