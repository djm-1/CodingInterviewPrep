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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL)
            q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                if(i==size-1){
                    TreeNode *tmp=q.front();
                    ans.push_back(tmp->val);
                }
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        
        return ans;
    }
};