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
    bool hasPathSum(TreeNode* root, int B) {
        if(!root) return false;
        if(!root->left and !root->right) return (bool)(B==root->val);
        int val=root->val;
        return ((root->left?hasPathSum(root->left,B-val):0) or (root->right?hasPathSum(root->right,B-val):0));
    }
};