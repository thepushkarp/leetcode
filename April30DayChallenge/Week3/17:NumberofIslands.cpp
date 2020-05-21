class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if (r == 0) return 0;
        int c = grid[0].size();
        vector<vector<int>> visited(r, vector<int>(c, 0));
        int islands = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1' and !visited[i][j]) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;
                    islands++;
                    while (!q.empty()) {
                        int cr = q.front().first;
                        int cc = q.front().second;
                        if (cr > 0) {
                            if (grid[cr - 1][cc] == '1' and !visited[cr - 1][cc]) {
                                q.push(make_pair(cr - 1, cc));
                                visited[cr - 1][cc] = 1;
                            }
                        }
                        if (cc > 0) {
                            if (grid[cr][cc - 1] == '1' and !visited[cr][cc - 1]) {
                                q.push(make_pair(cr, cc - 1));
                                visited[cr][cc - 1] = 1;
                            }
                        }
                        if (cr < r - 1) {
                            if (grid[cr + 1][cc] == '1' and !visited[cr + 1][cc]) {
                                q.push(make_pair(cr + 1, cc));
                                visited[cr + 1][cc] = 1;
                            }
                        }
                        if (cc < c - 1) {
                            if (grid[cr][cc + 1] == '1' and !visited[cr][cc + 1]) {
                                q.push(make_pair(cr, cc + 1));
                                visited[cr][cc + 1] = 1;
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return islands;
    }
};
