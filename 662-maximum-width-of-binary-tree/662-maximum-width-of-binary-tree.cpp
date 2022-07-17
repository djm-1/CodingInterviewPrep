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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,1});
        
        int maxi=1;
        
        while(!q.empty())
        {
            int sz=q.size();
            int mini=q.front().second;
            
            vector<int>ans;
            
            for(int i=0;i<sz;i++)
            {
                auto x=q.front();
                q.pop();
                x.second-=mini;
                
                if(x.first->left){
                    q.push({x.first->left,2LL*x.second});
                    ans.push_back(2LL*x.second);
                }
                
                if(x.first->right){
                    q.push({x.first->right,2LL*x.second+1});
                    ans.push_back(2LL*x.second+1);
                }
            }
            
            int n=ans.size();
            if(n>0)
            {
                maxi=max(maxi,ans[n-1]-ans[0]+1);
            }
                
        }
        
        return maxi;
    }
};