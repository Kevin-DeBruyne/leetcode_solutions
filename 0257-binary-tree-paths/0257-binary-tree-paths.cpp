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
    vector<string>res;
    void dfs(TreeNode *root, int cnt, string temp){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            res.push_back(temp);
            return;
        }
        int leftsum;
        int rightsum;
        string left=temp;
        string right=temp;
        if(root->left){
            left+="->";
            string t=to_string(root->left->val);
            left+=t;
        }
        if(root->right){
            right+="->";
            string t=to_string(root->right->val);
            right+=t;
        }
        
        dfs(root->left, cnt+1, left);
        dfs(root->right, cnt+1, right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        int sum=root->val;
        string t=to_string(root->val);
        if(!root->left && !root->right){
            return {t};
        }
        string temp=t;
        dfs(root, 0, temp);
        return res;
    }
};