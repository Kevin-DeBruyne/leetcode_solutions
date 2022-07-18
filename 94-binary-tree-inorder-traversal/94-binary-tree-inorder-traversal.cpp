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
    vector<int>res;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        while(true){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                root=st.top();
                st.pop();
                res.push_back(root->val);
                root=root->right;
            }
        }
        return res;
    }
//     vector<int>res;
//     vector<int> inOrder(Node* root)
//     {
//     stack<Node*>st;
//         while(true){
//             if(root!=NULL){
//                 st.push(root);
//                 root=root->left;
//             }
//             else{
//                 if(st.empty()){
//                    break;
//                 }
//                 root=st.top();
//                 st.pop();
//                 res.push_back(root->data);
//                 root=root->right;
                
//             }
            
            
//         }
//     return res;
        
//     }
};