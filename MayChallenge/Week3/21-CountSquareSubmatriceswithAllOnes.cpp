class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int r = matrix.size();
        if (!r) return ans;
        int c = matrix[0].size();
        for (int i = 0; i < r; i++)
            ans += matrix[i][c-1];
        for (int i = 0; i < c; i++)
            ans += matrix[r-1][i];
        ans -= matrix[r-1][c-1];
        for(int i = r - 2;i >= 0; i--){
         for(int j = c - 2 ;j >= 0; j--){
            matrix[i][j] = matrix[i][j] == 1? 1 + min({matrix[i+1][j+1],matrix[i] [j+1],matrix[i+1][j]}) : 0;
            ans += matrix[i][j];
         }
      }
      return ans;
    }
};
