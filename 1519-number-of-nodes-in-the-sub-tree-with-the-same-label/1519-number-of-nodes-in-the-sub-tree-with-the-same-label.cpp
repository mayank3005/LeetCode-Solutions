class Solution {
public:
    vector<int> ans;
    unordered_map<char, int> cnt;
    string labels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n, vector<int>());
        ans.resize(n);
        this->labels = labels;
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            tree[n1].push_back(n2);
            tree[n2].push_back(n1);
        }
        dfs(tree, -1, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& tree, int parent, int current) {
        int cCnt = cnt[labels[current]];
        cnt[labels[current]]++;
        for (int sub : tree[current]) {
            if (sub == parent) continue;
            dfs(tree, current, sub);
        }
        ans[current] = cnt[labels[current]] - cCnt;
    }
};