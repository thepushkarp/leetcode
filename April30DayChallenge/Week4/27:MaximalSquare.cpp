class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int r = matrix.size();
        if(!r) return 0;
        int c = matrix[0].size();
        vector<vector<int>> m(r, vector <int>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                m[i][j] = matrix[i][j] - '0';
                ans = max(m[i][j], ans);
            }
        }
        for(int i = r - 2; i >= 0; i--) {
            for(int j = c - 2; j >= 0; j--){
                if(m[i][j]) {
                    m[i][j] = 1 + min({m[i+1][j], m[i][j+1], m[i+1][j+1]});
                }
                ans = max(ans, m[i][j]);
            }
        }
        return ans*ans;
    }
};
