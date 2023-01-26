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
    int deep=0;
    void dp(TreeNode* root, int h){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            deep=max(h, deep);
        }
        dp(root->left, h+1);
        dp(root->right, h+1);
    }
    int ans=0;
    void dfs(TreeNode* root, int h, int deep){
        if(!root){
            return;
        }
        if(h==deep){
            ans+=root->val;
        }
        dfs(root->left, h+1, deep);
        dfs(root->right, h+1, deep);
    }
    int deepestLeavesSum(TreeNode* root) {
        dp(root, 0);
        dfs(root, 0, deep);
        cout<<deep<<endl;
        return ans;
    }
};