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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root==NULL)
        return v;
        q.push(root);
        int c=0;
        while(!q.empty()){
            vector<int> vtr;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(temp->left!=NULL)q.push(temp->left);
                if(temp->right!=NULL)q.push(temp->right);
                vtr.push_back(temp->val);
            }
            c++;
            if(c%2!=0){
                v.push_back(vtr);
            }
            else
            {
                reverse(vtr.begin(),vtr.end());
                v.push_back(vtr);
            }
            vtr.clear();
        }
        return v;
    }
};