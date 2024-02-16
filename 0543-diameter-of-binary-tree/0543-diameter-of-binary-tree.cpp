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
    int ans=0;
    int f(TreeNode* root){
        if(!root) return 0;
        return 1+max(f(root->left),f(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        int lh=f(root->left),rh=f(root->right);
        return ans=max(ans,lh+rh);
    }
};