// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    unordered_map<Node*,Node*>mp;
    unordered_map<Node*,bool>visited;
    Node* targetNode;
    int Target;
    
    void parent(Node *root)
    {
        if(root==NULL)
            return;
        if(root->left)
            mp[root->left]=root;
        if(root->right)
            mp[root->right]=root;
        if(root->data==Target)
            targetNode=root;
        parent(root->left);
        parent(root->right);
    }
    
    
    
    int dfs(Node* root){
        if(root==NULL||visited[root]==true)
            return 0;
        visited[root]=true;
        int ans=0;
        
        if(root->left)
            ans=max(ans,dfs(root->left));
        if(root->right)
            ans=max(ans,dfs(root->right));
        if(mp[root])
            ans=max(ans,dfs(mp[root]));
        
        return ans+1;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Target=target;
        parent(root);
        return dfs(targetNode)-1;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends