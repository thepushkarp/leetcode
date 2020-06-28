class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if (sLen > tLen) return false;
        int curr = 0;
        for (int i = 0; i < tLen; i++) {
            if (t[i] == s[curr]) {
                curr++;
            }
            if (curr == sLen) return true;
        }
        return curr == sLen;
    }
};
