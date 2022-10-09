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

class iter{
    stack<TreeNode*> st;
    // rev -- true --> next()
    // rev -- false --> prev()
    bool rev; 
    TreeNode *root;
    void pushl(TreeNode *node){
        while(node){
            st.push(node);
            node=(rev?node->left:node->right);
        }
    }
public:
    iter(TreeNode *root,bool rev){
        this->rev=rev;
        this->root=root;
        pushl(root);
    }
    int next(){
        auto node=st.top();st.pop();
        if(rev) pushl(node->right);
        else pushl(node->left);
        return node->val;
    }
};

class Solution {
public:    
    bool findTarget(TreeNode* root, int k) {
        iter l(root,true),r(root,false);
        int i=l.next(),j=r.next();
        while(i<j){
            if(i+j==k) return true;
            if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};