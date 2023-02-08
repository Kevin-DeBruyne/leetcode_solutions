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
    int ans=INT_MAX;
    TreeNode* pre;
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        if(pre!=NULL){
            ans=min(ans, abs(pre->val-root->val));
        }
        pre=root;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};