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
    
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        TreeNode* l=increasingBST(root->left);
        TreeNode* r=increasingBST(root->right);
        if(l==NULL){
            root->right=r;
            return root;
        }
        TreeNode* p=l;
        while(p->right){
            p=p->right;
        }
        root->left=NULL;
        p->right=root;
        root->right=r;
        return l;
    }
};
