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
    int f(TreeNode* root,int &height){
        if(!root) return 0;
        int lh=0,rh=0;   
        int a=f(root->left,lh),b=f(root->right,rh);
        height=1+max(lh,rh); 
        return max({a,b,lh+rh});
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height;
        return f(root,height);
    }
};