/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>adj[500];
    void makeAdj(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        makeAdj(root->left);
        makeAdj(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeAdj(root);
        queue<int>q;
        q.push(target->val);
        int vis[500]={0};
        vector<int>ans;
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            lvl++;
            for(int i=0;i<n;i++){
                int node=q.front();
                q.pop();
                if(lvl==k+1){
                    ans.push_back(node);
                }
                vis[node]=1;
                for(auto x:adj[node]){
                    if(!vis[x]){
                        q.push(x);
                    }
                }
            }
        }
    return ans;
    }
};