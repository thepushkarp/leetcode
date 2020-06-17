class Solution {
public:
    void floodFill(vector<vector<char>>& board, int sr, int sc, vector<vector<int>>& visited) {
        int rowSize = board.size();
        int colSize = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while(q.size() > 0) {
            int r = q.front().first;
            int c = q.front().second;
            visited[r][c] = 1;
            if (r > 0) {
                if (board[r-1][c] == 'O' and !visited[r-1][c]) {
                    q.push(make_pair(r-1, c));
                    visited[r-1][c] = 1;
                }
            }
            if (r < rowSize - 1) {
                if (board[r+1][c] == 'O' and !visited[r+1][c]) {
                    q.push(make_pair(r+1, c));
                    visited[r+1][c] = 1;
                }
            }
            if (c > 0) {
                if (board[r][c-1] == 'O' and !visited[r][c-1]) {
                    q.push(make_pair(r, c-1));
                    visited[r][c-1] = 1;
                }
            }
            if (c < colSize  - 1) {
                if (board[r][c+1] == 'O' and !visited[r][c+1]) {
                    q.push(make_pair(r, c+1));
                    visited[r][c+1] = 1;
                }
            }
            q.pop();
        }
    }
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        if (r == 0) return;
        int c = board[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
            if (board[i][0] == 'O' and !visited[i][0])
                floodFill(board, i, 0, visited);
        for (int i = 0; i < r; i++)
            if (board[i][c-1] == 'O' and !visited[i][c-1])
                floodFill(board, i, c-1, visited);
        for (int i = 0; i < c; i++)
            if (board[0][i] == 'O' and !visited[0][i])
                floodFill(board, 0, i, visited);
        for (int i = 0; i < c; i++)
            if (board[r-1][i] == 'O' and !visited[r-1][i])
                floodFill(board, r-1, i, visited);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (board[i][j] == 'O' and !visited[i][j])
                    board[i][j] = 'X', visited[i][j] = 1;
    }
};

