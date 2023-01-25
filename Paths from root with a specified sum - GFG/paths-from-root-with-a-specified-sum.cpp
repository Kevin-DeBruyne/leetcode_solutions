//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

	// Create the root of the tree
	Node* root = newNode(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size()) {

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N") {

			// Create the left child for the current node
			currNode->left = newNode(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())
			break;
		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N") {

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
//User function Template for C++

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    public:
    vector<vector<int>>res;
    void dfs(Node *root, int target, int sum, int cnt, vector<int>temp){
        if(root==NULL){
            return;
        }
        if(sum==target && cnt>0){
            res.push_back(temp);
            return;
        }
        int leftsum;
        int rightsum;
        vector<int>left=temp;
        vector<int>right=temp;
        if(root->left){
            leftsum=sum+root->left->key;
            left.push_back(root->left->key);
        }
        if(root->right){
            rightsum=sum+root->right->key;
            right.push_back(root->right->key);
        }
        
        dfs(root->left, target, leftsum, cnt+1, left);
        dfs(root->right, target, rightsum, cnt+1, right);
    }
    vector<vector<int>> printPaths(Node *root, int targetSum)
    {
        if(root==NULL){
            return {};
        }
        int sum=root->key;
        if(!root->left && !root->right){
            if(sum==targetSum){
                return {{root->key}};
            }
        }
        vector<int>temp{root->key};
        dfs(root, targetSum, sum, 0, temp);
        return res;
    }
};

//{ Driver Code Starts.

int main ()
{

	int t;
	cin >> t;
	getchar();

	while (t--)
	{

		int sum;
		cin >> sum;
		getchar();

		string inp;
		getline(cin, inp);

		struct Node* root = buildTree(inp);

        Solution ob;
		vector<vector<int>> ans = ob.printPaths(root, sum);
		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << " ";

			cout << "\n";
		}

	}

	return 0;
}
// } Driver Code Ends