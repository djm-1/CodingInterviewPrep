/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *clone(Node *node, unordered_map<Node*,Node*>&mp){
        
        if(!mp[node])
        {
            Node *newNode=new Node(node->val);
            mp[node]=newNode;
            for(auto x: node->neighbors)
            {
                if(mp[x])
                {
                    newNode->neighbors.push_back(mp[x]);
                }
                else
                {
                    Node *clone_neighbor=clone(x,mp);
                    newNode->neighbors.push_back(mp[x]);
                }
            }
        }
        
        return mp[node];
        
    }
    
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        
        if(node==NULL)
            return NULL;
        if(node!=NULL && node->neighbors.size()==0)
        {
            Node *cloneNode=new Node(node->val);
            return cloneNode;
        }
        return clone(node,mp);
    }
};