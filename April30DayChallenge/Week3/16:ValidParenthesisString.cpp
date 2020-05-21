class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                hi--;
                if (lo > 0) lo--;
            }
            if (s[i] == '(') {
                lo++;
                hi++;
            }
            if (s[i] == '*') {
                hi++;
                if (lo > 0) {
                    lo--;
                }
            }
            if (hi < 0) return false;
        }
        if (lo == 0) return true;
        else return false;
    }
};
