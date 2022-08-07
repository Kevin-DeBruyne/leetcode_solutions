/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*>vec;
    void pre(TreeNode* root, TreeNode* target){
        if(root==NULL){
            return;
        }
        vec.push_back(root);
        pre(root->left, target);
        pre(root->right, target);
        
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        pre(cloned,target);
        for(auto x:vec){
            if(x->val==target->val){
                return x;
            }
        }
        return NULL;
        
    }
};