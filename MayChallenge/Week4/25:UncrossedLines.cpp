class Solution {
public:
    int maxLines(int a, int b, vector<int>& A, vector<int>& B, int la, int lb, vector<vector<int>>& dp) {
        if (a >= la or b >= lb) {
            return 0;
        }
        else if (dp[a][b] != -1) {
            return dp[a][b];
        }
        else if (A[a] == B[b]) {
            return (1 + maxLines(a + 1, b + 1, A, B, la, lb, dp));
        }
        else {
            dp[a][b] = max(maxLines(a + 1, b, A, B, la, lb, dp), maxLines(a, b + 1, A, B, la, lb, dp));
            return dp[a][b];
        }
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int la = A.size(), lb = B.size();
        vector<vector<int>> dp(la, vector<int>(lb, -1));
        return maxLines(0, 0, A, B, la, lb, dp);
    }
};

