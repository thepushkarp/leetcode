class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int lcsTable[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    lcsTable[i][j] = 0;
                else if (text1[i - 1] == text2[j - 1])
                    lcsTable[i][j] = lcsTable[i - 1][j - 1] + 1;
                else
                    lcsTable[i][j] = max(lcsTable[i - 1][j], lcsTable[i][j - 1]);
            }
        }
        return lcsTable[m][n];
    }
};
