class Trie {
public:
    /** Initialize your data structure here. */
    static const int ALPHA_SIZE = 26;
    Trie* character[ALPHA_SIZE];
    bool endOfWord;
    Trie() {
        this -> endOfWord = false;
        for (int i = 0; i < ALPHA_SIZE; i++) {
            this -> character[i] = nullptr;
        }
    }

    /** Inserts a word into the trie. */
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

    /** Returns if the word is in the trie. */
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

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (this == nullptr) {
            return false;
        }
        Trie* curr  = this;
        for (int i = 0; i < prefix.size(); i++) {
            curr = curr -> character[prefix[i] - 'a'];
            if (curr == nullptr) {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
