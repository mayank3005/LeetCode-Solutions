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
        int countNodes(TreeNode* root) {
            if(!root) return 0;
            int lh = height(root->left);
            int rh = height(root->right);     
            if(lh == rh) 
               return (1 << lh) + countNodes(root->right);           
            else 
               return (1 << rh) + countNodes(root->left);  
        }
    private:
        int height(TreeNode *root){ //get the height of a complete binary tree.
            if(!root) return 0;
            return 1 + height(root->left);
        }
    };