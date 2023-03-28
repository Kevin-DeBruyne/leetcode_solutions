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
    vector<int> adj[100001];
    void makeAdj(TreeNode* root){
        if(root==NULL){
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
    int amountOfTime(TreeNode* root, int start) {
        makeAdj(root);
        queue<int>q;
        q.push(start);
        int vis[100001]={0};
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            lvl++;
            for(int i=0;i<n;i++){
                int node=q.front();
                vis[node]=1;
                q.pop();
                for(auto x:adj[node]){
                    if(!vis[x]){
                        q.push(x);
                    }
                }
            }
        }
        return lvl-1;
    }
};