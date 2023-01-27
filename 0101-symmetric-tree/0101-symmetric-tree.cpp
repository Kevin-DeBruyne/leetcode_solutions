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
    vector<int>left;
    vector<int>right;
    void dfs1(TreeNode* root){
        if(root==NULL){
            left.push_back(-1);
            return;
        }
        dfs1(root->left);
        dfs1(root->right);
        left.push_back(root->val);
    }
    void dfs2(TreeNode* root){
        if(root==NULL){
            right.push_back(-1);
            return;
        }
        dfs2(root->right);
        dfs2(root->left);
        right.push_back(root->val);
    }
    bool isSymmetric(TreeNode* root) {
        dfs1(root->left);
        dfs2(root->right);
	    // int l=0;
	    // int r=vec.size()-1;
	    for(auto x:left){
            cout<<x<<" ";
        }
        cout<<endl;
        for(auto x:right){
            cout<<x<<" ";
        }
        cout<<endl;
	    return left==right;
    }
};