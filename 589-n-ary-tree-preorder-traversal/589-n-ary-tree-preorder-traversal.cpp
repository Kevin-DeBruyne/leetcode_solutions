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
    stack<Node*>st;
    vector<int>vec;
    vector<int> preorder(Node* root) {
        if(root==NULL){
            return vec;
        }
        st.push(root);
        while(!st.empty()){
            int temp=st.top()->val;
            Node* p=st.top();
            st.pop();
            vec.push_back(temp);
            for (auto it =  p->children.rbegin(); it != p->children.rend(); ++it){
                st.push(*it);
            }
        }
        return vec;
    }
};