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
    
    int solve(TreeNode *root,int &ans){
        if(!root) return 0;
        int l=solve(root->left,ans);
        int r=solve(root->right,ans);
        int val=max(root->val,max(root->val+l,root->val+r));
        ans=max(ans,max(val,root->val+l+r));
        return val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};