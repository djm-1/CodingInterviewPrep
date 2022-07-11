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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto x=q.front();
            q.pop();
            
            TreeNode *temp=x.first;
            int level=x.second.first;
            int index=x.second.second;
            
            mp[index][level].push_back(temp->val);
            
            if(temp->left)
                q.push({temp->left,{level+1,index-1}});
            if(temp->right)
                q.push({temp->right,{level+1,index+1}});
        }
        
        vector<vector<int>>ans;
        for(auto x:mp){
            
            vector<int>t;
            for(auto y:x.second)
            {
                vector<int>smol=y.second;
                sort(smol.begin(),smol.end());
                for(auto m:smol)
                   t.push_back(m); 
            }
            ans.push_back(t);
        }
        
        return ans;
    
    }
};