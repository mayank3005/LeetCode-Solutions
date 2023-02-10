class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> Queue;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    Queue.push({i, j});
            }
        }
        if(Queue.size() == m * n) return -1;
        int ans = -1;
        pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!Queue.empty()) {
            ans++;
            int s = Queue.size();
            for(int i = 0; i < s; i++) {
                pair<int, int> curr = Queue.front();
                Queue.pop();
                for(pair<int, int> dir: dirs) {
                    int x = curr.first + dir.first;
                    int y = curr.second + dir.second;
                    if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 0) {
                        grid[x][y] = 1;
                        Queue.push({x, y});
                    }
                }
            }
        }
        return ans;
    }
};