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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            set<int>st;
            int n=q.size();
            TreeNode* node;
            TreeNode* l;
            TreeNode* r;
            for(int i=0;i<n;i++){
                node=q.front();
                q.pop();
                // cout<<node->val<<" ";
                st.insert(node->val);
                if(node->left){
                    q.push(node->left);
                    if(node->left->val==x){
                        l=node;
                    }
                    if(node->left->val==y){
                        r=node;
                    }
                }
                if(node->right){
                    q.push(node->right);
                    if(node->right->val==x){
                        l=node;
                    }
                    if(node->right->val==y){
                        r=node;
                    }
                }
            }
            // cout<<endl;
            if(l!=r && st.find(x)!=st.end() && st.find(y)!=st.end()){
                return true;
            }
        }
        return false;
    }
};