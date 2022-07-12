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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool check=false;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x==NULL)
                check=true;
            else
            {
                if(check){
                    return false;
                }
                else
                {
                    q.push(x->left);
                    q.push(x->right);
                }
            }
        }
        
        return true;
    }
};