class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        if (!r) return 0;
        int c = dungeon[0].size();
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, INT_MAX));
        dp[r-1][c] = 1;
        dp[r][c-1] = 1;
        for (int i = r-1; 0 <= i; i--) {
            for (int j = c-1; 0 <= j; j--) {
                int cost = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(1, cost);
            }
        }
        return dp[0][0];
    }
};
