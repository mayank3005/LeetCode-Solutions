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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            int sz=q.size();
            int lt,rt,curmin=q.front().second;
            for(int i=0;i<sz;i++){
                root=q.front().first;
                int curid=q.front().second-curmin;
                q.pop();
                if(i==0) lt=curid;
                if(i==sz-1) rt=curid;
                if(root->left) q.push({root->left,(long long)curid*2});
                if(root->right) q.push({root->right,(long long)curid*2+1});

            }
            ans=max(ans,rt-lt+1);
        }
        return ans;
    }
};