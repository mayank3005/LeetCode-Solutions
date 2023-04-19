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
    pair<int,int> f(TreeNode *root,int &ans){
        if(!root) return {-1,-1};
        int l=f(root->left,ans).second;
        int r=f(root->right,ans).first;
        ans=max(ans,1+max(l,r));
        return {1+l,1+r};
    }
    int longestZigZag(TreeNode* root) {
        int ans=-1;
        f(root,ans);
        return ans;
    }
};