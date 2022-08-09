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
    vector<int>vec;
    void trav(Node* root) {
        if(root==NULL){
            return;
        }
        vec.push_back(root->val);
        for(auto x:root->children){
            trav(x);
        }
    }
    vector<int> preorder(Node* root) {
        if(root==NULL){
            return vec;
        }
        trav(root);
        return vec;
    }
};