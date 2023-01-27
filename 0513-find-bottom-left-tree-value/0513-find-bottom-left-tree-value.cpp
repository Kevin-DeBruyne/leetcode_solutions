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
    int res=INT_MIN;
    void dfs(TreeNode* root, int cnt){
        if(!root){
            res=max(res, cnt);
            return;
        }
        dfs(root->left, cnt+1);
        dfs(root->right, cnt+1);
    }
    int ans;
    void solve(TreeNode* root, int cnt, int res){
        if(!root){
            return;
        }
        cout<<cnt<<" ";
        if(cnt==res){
            ans=root->val;
        }
        solve(root->right, cnt+1, res);
        solve(root->left, cnt+1, res);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root, 0);
        cout<<res<<endl;
        solve(root, 1, res);
        return ans;
    }
};