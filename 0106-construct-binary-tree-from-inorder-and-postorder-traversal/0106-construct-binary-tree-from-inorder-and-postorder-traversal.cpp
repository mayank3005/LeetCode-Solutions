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
    
    TreeNode* solve(vector<int> &in,int is,int ie,vector<int> &post,int ps,int pe,map<int,int> &mp){
        
        if(is>ie or ps>pe) return NULL;
        
        TreeNode *root = new TreeNode(post[pe]);
        int iroot=mp[post[pe]];
        int eleLeft = iroot-is;
        
        root->left = solve(in,is,iroot-1,post,ps,ps+eleLeft-1,mp);
        root->right = solve(in,iroot+1,ie,post,ps+eleLeft,pe-1,mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        
        return solve(inorder,0,n-1,postorder,0,n-1,mp);
    }
};