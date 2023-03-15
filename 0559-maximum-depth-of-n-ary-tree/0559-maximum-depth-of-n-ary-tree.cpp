/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int height=1;
    void dfs(Node* root, int h){
        if(root==NULL){
            return;
        }
        for(auto x:root->children){
            cout<<h<<" ";
            if(x){
                dfs(x, h+1);
                height=max(height, h);
            }
        }
        
    }
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        if(!root->children.size()){
            return 1;
        }
        dfs(root, 1); 
        // for(auto x:root->children){
        //     cout<<x->val<<endl;   
        // }
        return height+1;
        
    }
};