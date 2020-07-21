class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>> visited, int word_index, string word) {
        // cout << i << " " << j << " " << board[i][j] << " " << word_index << endl;
        int n = board.size();
        int m = board[0].size();
        visited[i][j] = 1;
        if (word_index >= word.size()) {
            return false;
        }
        if (board[i][j] != word[word_index]) {
            return false;
        }
        if (word_index == word.size() - 1) {
            return true;
        }
        else {
            if (i > 0 and !visited[i-1][j]) {
                if (dfs(board, i - 1, j, visited, word_index + 1, word)) {
                    return true;
                }
            }
            if (i < n - 1 and !visited[i+1][j]) {
                if (dfs(board, i + 1, j, visited, word_index + 1, word)) {
                    return true;
                }
            }
            if (j > 0 and !visited[i][j-1]) {
                if (dfs(board, i, j - 1, visited, word_index + 1, word)) {
                    return true;
                }
            }
            if (j < m - 1 and !visited[i][j+1]) {
                if (dfs(board, i, j + 1, visited, word_index + 1, word)) {
                    return true;
                }
            }
            visited[i][j] = 0;
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int w = word.size();
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // cout << i << " " << j << endl;
                int word_index = 0;
                if (board[i][j] == word[word_index]) {
                    if (dfs(board, i, j, visited, word_index, word) == true) {
                        return true;
                    }
                    
                }
            }
        }
        return false;
    }
};
