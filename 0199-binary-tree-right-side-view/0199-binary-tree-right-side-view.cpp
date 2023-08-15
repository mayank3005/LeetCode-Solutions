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
    vector<int> ans;
    void f(TreeNode *root,int lvl){
        if(!root) return;
        if(ans.size()==lvl) ans.push_back(root->val);
        f(root->right,lvl+1); f(root->left,lvl+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        f(root,0);
        return ans;
    }
};