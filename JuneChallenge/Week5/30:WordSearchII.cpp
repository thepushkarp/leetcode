class Trie {
public:
    static const int ALPHA_SIZE = 26;
    Trie* character[ALPHA_SIZE];
    bool endOfWord;
    Trie() {
        this -> endOfWord = false;
        for (int i = 0; i < ALPHA_SIZE; i++) {
            this -> character[i] = nullptr;
        }
    }
    void insert(string word) {
        Trie* curr = this;
        for (int i = 0; i < word.size(); i++) {
            if (curr -> character[word[i] - 'a'] == nullptr) {
                curr -> character[word[i] - 'a'] = new Trie();
            }
            curr = curr -> character[word[i] - 'a'];
        }
        curr -> endOfWord = true;
    }
    bool search(string word) {
        if (this == nullptr) {
            return false;
        }
        Trie* curr  = this;
        for (int i = 0; i < word.size(); i++) {
            curr = curr -> character[word[i] - 'a'];
            if (curr == nullptr) {
                return false;
            }
        }
        return curr -> endOfWord;
    }
};


class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, Trie* trie, unordered_set<string>& result, string s){
        char c = board[i][j];
        if(c == '$') return;
        board[i][j] = '$';
        Trie* t = trie->character[c - 'a'];
        if(t){
            string ss = s + c;
            if(t->endOfWord) result.insert(ss);
            if(i < board.size()-1) dfs(board, i+1, j, t, result, ss);
            if(i > 0) dfs(board, i-1, j, t, result, ss);
            if(j < board[0].size()-1) dfs(board, i, j+1, t, result, ss);
            if(j > 0) dfs(board, i, j-1, t, result, ss);
        }
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size() == 0) return {};
        Trie trie;
        for(string w: words){
            trie.insert(w);
        }
        unordered_set<string> result_s;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                dfs(board, i, j, &trie, result_s, "");
            }
        }
        vector<string> result(result_s.begin(), result_s.end());
        return result;
    }
};

