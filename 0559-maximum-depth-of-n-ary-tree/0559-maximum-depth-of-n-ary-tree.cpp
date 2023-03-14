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
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        queue<Node*>q;
        q.push(root);
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            lvl++;
            for(int i=0;i<n;i++){
                Node* n=q.front();
                q.pop();
                for(auto x:n->children){
                    if(x){
                        q.push(x);
                    }
                }
            }
        }
        // for(auto x:root->children){
        //     cout<<x->val<<endl;
        // }        
        return lvl;
        
    }
};