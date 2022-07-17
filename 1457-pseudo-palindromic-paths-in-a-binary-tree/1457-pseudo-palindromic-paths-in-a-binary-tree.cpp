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
    int count=0;
    unordered_map<int,int>mp;
    
    bool checkPalindrome(){
        
        int odd=0;
        for(auto x:mp)
        {
            if(x.second%2==1)
                odd++;
        }
        
        return odd>1?false:true;
    }
    
    
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        
        mp[root->val]++;
        
        if(root->right==NULL && root->left==NULL)
        {
            if(checkPalindrome())
                count++;
        }
        
        helper(root->left);
        helper(root->right);
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        helper(root);
        return count;
    }
};