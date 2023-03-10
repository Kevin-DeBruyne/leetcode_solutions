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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            level++;
            int even=INT_MAX;
            int odd=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                if(level%2==0){
                    if((node->val&1) or (node->val>=even)){
                        return false;
                    }
                    else{
                        even=node->val;
                    }
                }
                else{
                    if((node->val&1)==0 or (node->val<=odd)){
                        return false;
                    }
                    else{
                        odd=node->val;
                    }
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                q.pop();
            }
        }
        return true;
    }
};