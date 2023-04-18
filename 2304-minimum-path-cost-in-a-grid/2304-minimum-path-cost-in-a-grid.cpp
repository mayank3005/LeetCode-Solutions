class Solution {
public:
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visitedCost(m, vector<int>(n, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // push all in the first row to the pq
    for(int j=0; j<n; j++)
        pq.push({grid[0][j], 0, j});

    while(!pq.empty()){
        int costTillHere = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();

        if(x == m-1)
            return costTillHere;

        for(int dy = 0; x+1 < m && dy < n; dy++){
            int newCost = costTillHere  + moveCost[grid[x][y]][dy] + grid[x+1][dy];
            if(newCost < visitedCost[x+1][dy]){
                visitedCost[x+1][dy] =  newCost;
                pq.push({newCost, x+1, dy});
            }
        }
    }
    return -1;
}
};