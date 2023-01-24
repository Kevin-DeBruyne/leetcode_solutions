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
    void dfs(TreeNode *root, string temp){
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
            char t=char(97+root->left->val);
            left+=t;
        }
        if(root->right){
            char t=char(97+root->right->val);
            right+=t;
        }
        dfs(root->left, left);
        dfs(root->right, right);
    }
    string smallestFromLeaf(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        // int sum=root->val;
        char t=char(97+root->val);
        if(!root->left && !root->right){
            return {t};
        }
        string temp;
        temp.push_back(t);
        dfs(root, temp);
        for(int i=0;i<res.size();i++){
            reverse(res[i].begin(), res[i].end());
        }
        sort(res.begin(), res.end());
        for(auto x:res){
            cout<<x<<" ";
        }
        return res[0];
    }
};