class Solution {
public:
    int uniquePaths(int m, int n) {
        long ans = 1;
        for (int i = n; i < m + n -1; i++) {
            ans *= i;
            ans /= (i - n + 1);
        }
        return ans;
    }
};
