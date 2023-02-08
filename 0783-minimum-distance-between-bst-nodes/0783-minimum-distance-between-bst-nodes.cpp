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
    vector<int>vec;
    int ans=INT_MAX;
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        for(int i=0;i<vec.size()-1;i++){
            ans=min(ans, abs(vec[i+1]-vec[i]));
        }
        return ans;
    }
};