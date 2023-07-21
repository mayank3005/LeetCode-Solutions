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
    int res;
    // { sum , max , min }
    vector<int> f(TreeNode *root){
        if(!root) return {0,INT_MIN,INT_MAX};
        vector<int> left=f(root->left);
        vector<int> right=f(root->right);
        vector<int> ans;
        if(root->val<=left[1] or root->val>=right[2]) ans = {max(left[0],right[0]),INT_MAX,INT_MIN};
        else ans = {left[0]+right[0]+root->val,max(root->val,right[1]),min(root->val,left[2])},res=max(res,left[0]+right[0]+root->val);
        return ans;
    }
    int maxSumBST(TreeNode* root) {
        res=0;
        vector<int> ans=f(root);
        return res;
    }
};