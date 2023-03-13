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
    bool solve(TreeNode *a,TreeNode *b){
        if(!a or !b){
            return !a and !b;
        }
        return (solve(a->left,b->right) and solve(a->right,b->left) and (a->val==b->val));
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};