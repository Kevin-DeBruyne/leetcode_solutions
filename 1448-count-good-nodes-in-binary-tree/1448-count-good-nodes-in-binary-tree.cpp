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
    int cnt=INT_MIN;
    int ans=0;
    vector<vector<int>>vec;
    void dfs(TreeNode *root, int cnt){
        if(root==NULL){
            // cnt=root->val;
            return;
        }
        // temp.push_back(root->val);
        // if(!root->left && !root->right){
        //     vec.push_back(temp);
        // }
        if(root->val>=cnt){
            cout<<cnt<<" ";
            // cout<<endl;
            // cout<<root->val<<" ";
            cnt=root->val;
            ans++;
        }
        // cnt=root->val;
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<int>temp;
        int cnt=INT_MIN;
        dfs(root, cnt);
        // for(auto x:vec){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};