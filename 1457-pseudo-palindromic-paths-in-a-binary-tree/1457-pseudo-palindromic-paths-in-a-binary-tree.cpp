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
    bool check(unordered_map<int,int> &mp){
        int tot=0,odd=0;
        for(auto &[_,x]:mp){
            if(x&1) odd++;
            tot+=x;
        }
        return (odd<=1);
    }
    void f(TreeNode *root,unordered_map<int,int> &mp,int &ans){
        if(!root) return;
        mp[root->val]++;
        if(!root->left and !root->right){
            if(check(mp)) ans++;
            mp[root->val]--;
            return;
        }
        f(root->left,mp,ans);f(root->right,mp,ans);
        mp[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        unordered_map<int,int> mp;
        int ans=0;
        f(root,mp,ans);
        return ans;
    }
};