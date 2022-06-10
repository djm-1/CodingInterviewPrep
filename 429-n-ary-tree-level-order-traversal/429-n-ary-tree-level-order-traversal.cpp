/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root)
        {
            queue<Node*>Q;
            Q.push(root);
            while(!Q.empty()){
                int size=Q.size();
                vector<int>level;
                for(int i=0;i<size;i++)
                {
                    Node* node=Q.front();
                    Q.pop();
                    vector<Node*>children=node->children;
                    for(int i=0;i<children.size();i++)
                    {
                        if(children[i])Q.push(children[i]);
                    }
                    level.push_back(node->val);
                }
                ans.push_back(level);
            }
        }
        return ans;
    }
};