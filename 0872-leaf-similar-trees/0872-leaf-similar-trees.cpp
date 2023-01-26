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
    void dfs(TreeNode *root, vector<int>&res){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            res.push_back(root->val);
            return;
        }
        dfs(root->left,res);
        dfs(root->right,res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>res1;
        vector<int>res2;
        dfs(root1, res1);
        dfs(root2, res2);
        for(auto x:res1){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:res2){
            cout<<x<<" ";
        }
        return res1==res2;
    }
};