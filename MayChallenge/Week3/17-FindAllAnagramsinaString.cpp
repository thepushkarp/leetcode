class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans, sChars(26, 0), pChars(26, 0);
        int sLen = s.size();
        int pLen = p.size();
        if (sLen < pLen) return ans;
        for (int i = 0; i < pLen; i++) {
            sChars[s[i] - 'a']++;
            pChars[p[i] - 'a']++;
        }
        if (sChars == pChars) ans.push_back(0);
        for (int i = pLen; i < sLen; i++) {
            sChars[s[i] - 'a']++;
            sChars[s[i - pLen] - 'a']--;
            if (sChars == pChars) ans.push_back(i - pLen + 1);
        }
        return ans;
    }
};
