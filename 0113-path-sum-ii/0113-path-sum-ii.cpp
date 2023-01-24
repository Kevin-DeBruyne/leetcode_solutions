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
    vector<vector<int>>res;
    void dfs(TreeNode *root, int target, int sum, int cnt, vector<int>temp){
        if(root==NULL){
            return;
        }
        if(!root->left && !root->right){
            cout<<sum<<" ";
            cout<<cnt<<endl;
            if(sum==target && cnt>0){
                res.push_back(temp);
                return;
            }
        }
        int leftsum;
        int rightsum;
        vector<int>left=temp;
        vector<int>right=temp;
        if(root->left){
            leftsum=sum+root->left->val;
            left.push_back(root->left->val);
        }
        if(root->right){
            rightsum=sum+root->right->val;
            right.push_back(root->right->val);
        }
        
        dfs(root->left, target, leftsum, cnt+1, left);
        dfs(root->right, target, rightsum, cnt+1, right);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return {};
        }
        int sum=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                return {{root->val}};
            }
        }
        vector<int>temp{root->val};
        dfs(root, targetSum, sum, 0, temp);
        return res;
        }
};