class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        if (r == 0) return 0;
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j  = 0; j < c; j++) {
                if (i or j) {
                    int mini = INT_MAX;
                    if (i > 0) mini = grid[i - 1][j];
                    if (j > 0) mini = min(mini, grid[i][j - 1]);
                    grid[i][j] = mini + grid[i][j];
                }
            }
        }
        return grid[r - 1][c - 1];
    }
};
