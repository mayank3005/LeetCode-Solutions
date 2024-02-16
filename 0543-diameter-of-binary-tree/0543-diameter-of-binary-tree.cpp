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
    int ans=0; map<TreeNode*,int> height;
    int f(TreeNode* root){
        if(!root) return 0;
        return height[root] = 1+max(f(root->left),f(root->right));
    }
    int dd(TreeNode *root){
        if(!root) return 0;
        dd(root->left);
        dd(root->right);
        int lh=height[root->left],rh=height[root->right];
        return ans=max(ans,lh+rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        f(root);
        return dd(root);
    }
};