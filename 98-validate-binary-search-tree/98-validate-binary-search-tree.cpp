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
    void in(TreeNode* root){
        if(root==NULL){
            return;
        }
        in(root->left);
        vec.push_back(root->val);
        in(root->right);
    }
    bool isValidBST(TreeNode* root) {
        in(root);
        for(int i=0;i<vec.size()-1;i++){
            if(vec[i+1]<=vec[i]){
                return false;
            }
        }
        return true;
    }
};