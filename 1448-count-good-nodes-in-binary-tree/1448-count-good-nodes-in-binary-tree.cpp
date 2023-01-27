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
    int ans=0;
    void dfs(TreeNode *root, int cnt){
        if(root==NULL){
            return;
        }
        if(root->val>=cnt){
            cout<<cnt<<" ";
            cnt=root->val;
            ans++;
        }
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        int cnt=INT_MIN;
        dfs(root, cnt);
        return ans;
    }
};