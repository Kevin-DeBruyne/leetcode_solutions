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
    int res(string s){
        int n=s.length();
        int c=0;
        int val=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                val+=pow(2,c);
            }
            c++;
        }
        return val;
    }
    int ans=0;
    void dfs(TreeNode* root,string s)
    {
        
        if(!root){
            return;
        }
        if(root!=NULL && !root->left && !root->right){
            s+=to_string(root->val);
            ans+=res(s);
            return;
        }
        s+=to_string(root->val);
        dfs(root->left,s);
        dfs(root->right,s);
    }
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return ans;
    }
};