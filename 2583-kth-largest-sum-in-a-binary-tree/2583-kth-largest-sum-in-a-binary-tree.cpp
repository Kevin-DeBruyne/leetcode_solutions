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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            long long temp=0;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                temp+=node->val;
                if(node->left){
                    q.push(node->left);
                }            
                if(node->right){
                    q.push(node->right);
                }    
            }
            ans.push_back(temp);
        }
        if(ans.size()<k){
            return -1;
        }
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans[k-1];
    }
};