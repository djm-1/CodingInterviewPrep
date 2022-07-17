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
    typedef long long int ll;
    ll count=0;
    unordered_map<ll,ll>mp;
    
    void helper(TreeNode* root, ll targetSum, ll currSum){
        if(root==NULL)
            return;
        
        currSum+=(ll)root->val;
        
        if(currSum==targetSum)
            count++;
        
        if(mp.find(currSum-targetSum)!=mp.end())
            count+=mp[currSum-targetSum];
        
        mp[currSum]++;  // keep it later because if target=0 then bug
        
        helper(root->left,targetSum,currSum);
        helper(root->right,targetSum,currSum);
        
        mp[currSum]--;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,0);
        return count;
    }
};