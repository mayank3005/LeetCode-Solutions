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
    int idx;
    TreeNode *f(vector<int> &preorder,int mx,int mn){
        if(idx==preorder.size() or preorder[idx]>=mx or preorder[idx]<=mn) return NULL;
        TreeNode *newNode = new TreeNode(preorder[idx++]);
        newNode->left=f(preorder,newNode->val,mn);
        newNode->right=f(preorder,mx,newNode->val);
        return newNode;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        idx=0;
        return f(preorder,INT_MAX,INT_MIN);
    }
};