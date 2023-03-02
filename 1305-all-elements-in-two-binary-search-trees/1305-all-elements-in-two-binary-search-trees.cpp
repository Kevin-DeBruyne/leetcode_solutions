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
    vector<int>vec1;
    vector<int>vec2;
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        vec1.push_back(root->val);
        dfs(root->right);
    }
    void dfs1(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        vec2.push_back(root->val);
        dfs(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs1(root2);
        for(auto x:vec1){
            vec2.push_back(x);
        }
        sort(vec2.begin(), vec2.end());
        return vec2;
    }
};