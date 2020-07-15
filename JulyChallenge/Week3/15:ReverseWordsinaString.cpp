class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        istringstream iss(s);
        for(string s; iss >> s;) {
            tokens.push_back(s);
        }
        string res = "";
        for (int i = tokens.size() - 1; i > 0; i--) {
            res += tokens[i];
            res += ' ';
        }
        if (tokens.size() != 0) {
            res += tokens[0];
        }
        return res;
    }
};

