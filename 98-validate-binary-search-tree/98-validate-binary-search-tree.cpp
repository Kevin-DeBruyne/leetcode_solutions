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
    long long temp=-1e12;
    
    bool isValidBST(TreeNode* root) {
       if(!root)
           return true;
       bool res=isValidBST(root->left);
        if(res==false || root->val<=temp)
            return false;
        temp=max(temp,(long long)root->val);
        return isValidBST(root->right);
    }
};