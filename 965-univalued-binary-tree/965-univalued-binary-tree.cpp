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
    bool ans=true;
    vector<int>res;
    void in(TreeNode *root){
        if(!root){
            return;   
        }  
        res.push_back(root->val);
        in(root->left);
        in(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        in(root);
        for(int i=0;i<res.size()-1;i++){
            if(res[i]!=res[i+1]){
                ans=false;
                break;
            }
            
        }
        return ans;
    }
    
};