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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int count=0;
        
        if(root)
        {
            queue<TreeNode*>Q;
            Q.push(root);
            while(!Q.empty())
            {
                int size=Q.size();
                vector<int>level;
                for(int i=0;i<size;i++)
                {
                    TreeNode* node=Q.front();
                    Q.pop();
                    if(node->left)Q.push(node->left);
                    if(node->right)Q.push(node->right);
                    level.push_back(node->val);
                }
                if(count%2==1)
                {
                    reverse(level.begin(),level.end());
                }
                ans.push_back(level);
                count++;
            }
        }
        return ans;
    }
};