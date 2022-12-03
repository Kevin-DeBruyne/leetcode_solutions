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
    vector<vector<int>>ans;
    vector<int>vec;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        for(int i=0;i<queries.size();i++){
            int target=queries[i];
            // vector<int>::iterator upper1, upper2;
            if(target>vec[vec.size()-1]){
                ans.push_back({vec[vec.size()-1], -1});
            }
            else if(target<vec[0]){
                ans.push_back({-1, vec[0]});   
            }
            else{
                
            auto upper1 = lower_bound(vec.begin(), vec.end(), target);
            if(vec[upper1-vec.begin()]==target){
                ans.push_back({target, target});               
            }
            else{
                ans.push_back({vec[upper1-vec.begin()-1], vec[upper1-vec.begin()]});
            }
            }
        }
        return ans;
    }
};