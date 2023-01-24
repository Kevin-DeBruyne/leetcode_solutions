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
    bool is=false;
    void dfs(TreeNode *root, int target, int sum, int cnt){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            cout<<sum<<" ";
            cout<<cnt<<endl;
            if(sum==target && cnt>0){
                is=true;
                return;
            }
        }
        int leftsum;
        int rightsum;
        if(root->left){
            leftsum=sum+root->left->val;
        }
        if(root->right){
            rightsum=sum+root->right->val;
        }
        dfs(root->left, target, leftsum, cnt+1);
        dfs(root->right, target, rightsum, cnt+1);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        int sum=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                return true;
            }
        }
        dfs(root, targetSum, sum, 0);
        return is;
    }
};