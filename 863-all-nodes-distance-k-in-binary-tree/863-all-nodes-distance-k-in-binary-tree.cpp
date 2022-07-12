/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<TreeNode*,TreeNode*>mp;
    vector<int>ans;
    unordered_map<TreeNode*,bool>visited;
    
    void parent(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left)
            mp[root->left]=root;
        if(root->right)
            mp[root->right]=root;
        parent(root->left);
        parent(root->right);
    }
    
    void dfs(TreeNode *root,int k)
    {
        if(root==NULL||visited.find(root)!=visited.end())
            return;
        if(k==0)
        {
            ans.push_back(root->val);
        }
        visited[root]=true;
        if(root->left)
            dfs(root->left,k-1);
        if(root->right)
            dfs(root->right,k-1);
        if(mp[root])
            dfs(mp[root],k-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        parent(root);
        dfs(target,k);
        return ans;
    }
};