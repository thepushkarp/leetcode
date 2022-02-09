class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0, neighbours = 0;
        int r = grid.size();
        if (r == 0) return islands;
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    islands++;
                    if (i < r - 1 and grid[i + 1][j] == 1) neighbours++;
                    if (j < c - 1 and grid[i][j + 1] == 1) neighbours++;
                }
            }
        }
        return islands*4 - neighbours*2;
    }
};

