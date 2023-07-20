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
    map<int,int> mp;
    TreeNode* f(int ins,int ine,int &preIdx,vector<int> &pre,vector<int> &in){
        if(ins>ine) return NULL;
        TreeNode *node=new TreeNode(pre[preIdx++]);
        int idx=mp[pre[preIdx-1]];
        node->left=f(ins,idx-1,preIdx,pre,in);
        node->right=f(idx+1,ine,preIdx,pre,in);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        } 
        int preIdx=0;
        return f(0,inorder.size()-1,preIdx,preorder,inorder);
    }
};