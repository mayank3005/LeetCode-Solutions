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
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> inorder;
        while(root){
            if(root->left==NULL){
                inorder.push_back(root->val);
                root=root->right;
            }else{
                TreeNode *temp=root->left;
                while(temp->right and temp->right!=root){
                    temp=temp->right;
                }
                if(!temp->right) temp->right=root,root=root->left;
                else temp->right=NULL,inorder.push_back(root->val),root=root->right;
            }
        }
        return inorder;
        
    }
};