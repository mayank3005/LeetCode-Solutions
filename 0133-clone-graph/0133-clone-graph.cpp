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
    map<Node*,Node*> mp;
    Node* dfs(Node *root){
        if(mp.find(root)!=mp.end()) return mp[root];
        Node *node=new Node(root->val);
        mp[root]=node;
        for(auto it:root->neighbors){
            node->neighbors.push_back(dfs(it));
        }
        return node;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        mp.clear();
        return dfs(node);
    }
};