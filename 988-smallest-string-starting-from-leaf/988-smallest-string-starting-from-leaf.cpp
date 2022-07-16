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
    vector<string>store;
    void helper(TreeNode *root, string s)
    {
        if(root==NULL)
            return;
        s+=(char)('a'+root->val);
        if(!root->left && !root->right)
        {
            reverse(s.begin(),s.end());
            store.push_back(s);
            return;
        }
        helper(root->left,s);
        helper(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        helper(root,"");
        sort(store.begin(),store.end());
        return store[0];
    }
};