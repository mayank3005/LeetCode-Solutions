class Solution {
public:
	pair<int, int> getPosition(int index, int n){
        int row = n - 1 - index / n;
        int rowDiff = index - (n - 1 - row) * n + 1;
        int col;
        if((n - 1 - row) % 2){
            col = n - rowDiff;
        }
        else{
            col = rowDiff - 1;
        }
        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>&board){
        int n = board.size();
		vector<int>visited(n * n, -1);
		queue<int>bfs;
		bfs.push(0);
		visited[0] = 0;
		while(!bfs.empty()){
            int current = bfs.front();
            bfs.pop();
            for(int i = 1; i <= 6 && current + i < n * n; i++){
                int next = current + i;
                pair<int, int>p = getPosition(next, n);
                if(board[p.first][p.second] != -1){
                    next = board[p.first][p.second] - 1;
                }
                if(visited[next] == -1){
                    visited[next] = 1 + visited[current];
                    if(next == n * n - 1){
                        return visited[next];
                    }
                    bfs.push(next);
                }
            }
        }
        return -1;
    }
};