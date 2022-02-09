class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack <char> s, t;
        for (auto i: S) {
            if (i == '#') {
                if (not s.empty()) s.pop();
            }
            else s.push(i);
        }
        for (auto i: T) {
            if (i == '#') {
                if (not t.empty()) t.pop();
            }
            else t.push(i);
        }
        return t == s;
    }
};
