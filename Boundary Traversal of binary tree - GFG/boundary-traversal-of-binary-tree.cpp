//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    vector<int>vl;
    void l(Node* root){
        if(!root->left && !root->right){
            return;
        }
        // cout<<root->data<<endl;
        vl.push_back(root->data);
        if(root->left){
            l(root->left);
        }
        else{
            l(root->right);
        }
    }
    void dfs(Node* root){
        if(!root->left && !root->right){
            vl.push_back(root->data);
            return;
        }
        if(root->left){
            dfs(root->left);
        }
        if(root->right){
            dfs(root->right);
        }
    }
    stack<int>st;
    void r(Node* root){
        if(!root->left && !root->right){
            return;
        }
        st.push(root->data);
        // cout<<root->data<<endl;
        if(root->right){
            r(root->right);
        }
        else{
            r(root->left);
        }
    }
    vector <int> boundary(Node *root)
    {
        if(!root->left && !root->right){
            return {root->data};
        }
        if(root->left){
            l(root);
        }
        else{
            vl.push_back(root->data);
        }
        dfs(root);
        if(root->right){
            r(root);
        }
        if(!st.empty()){
            while(st.size()!=1){
                vl.push_back(st.top());
                st.pop();
            }
        }
        return vl;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends