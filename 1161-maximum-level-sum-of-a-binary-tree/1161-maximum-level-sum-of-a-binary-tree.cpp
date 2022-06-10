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
    int maxLevelSum(TreeNode* root) {
        vector<int>ans;
        int level=0;
        if(root)
        {
            queue<TreeNode*>Q;
            Q.push(root);
            while(!Q.empty())
            {
                int size=Q.size();
                int sum=0;
                for(int i=0;i<size;i++)
                {
                    TreeNode* node=Q.front();
                    Q.pop();
                    if(node->left)Q.push(node->left);
                    if(node->right)Q.push(node->right);
                    sum+=node->val;
                }
                ans.push_back(sum);                
            }
            
            for(int i=0;i<ans.size();i++)
            {
                if(ans[i]>ans[level])
                    level=i;
            }
            
        }
        return level+1;
    }
};