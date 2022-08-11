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
    unordered_map<int,int>mp;
    
    void helper(TreeNode *root)
    {
        if(root==NULL)
            return;
        mp[root->val]++;
        helper(root->left);
        helper(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        
        int maxi=-1;
        
        helper(root);
        
        for(auto x:mp)
        {
            maxi=max(maxi,x.second);
        }
        
        
        vector<int>ans;
        for(auto x:mp)
        {
            if(x.second==maxi)
                ans.push_back(x.first);
        }
        
        return ans;
    }
};