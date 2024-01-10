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
int st;
TreeNode *src=NULL;

class Solution {
public:
    
    void dfs(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &mp){
        
        if(!root) return;
        
        if(root->val==st) src=root;
        
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        
        dfs(root->left,mp);
        dfs(root->right,mp);
        
    }
    
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;
         unordered_map<TreeNode*,TreeNode*> parent;
        st=start;
        src=NULL;
        
        dfs(root,parent);
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int> vis;
        
        q.push(src);vis[src]=1;
        
        int lvl=-1;
        
        while(!q.empty()){
            int sz=q.size();
            lvl++;
            while(sz--){
                TreeNode *root=q.front();q.pop();
                if(root->left and !vis[root->left])
                    vis[root->left]=1,q.push(root->left);
                if(root->right and !vis[root->right])
                    vis[root->right]=1,q.push(root->right);
                if(parent[root] and !vis[parent[root]])
                    vis[parent[root]]=1,q.push(parent[root]);
            }
        }
        
        return lvl;   
    }
};