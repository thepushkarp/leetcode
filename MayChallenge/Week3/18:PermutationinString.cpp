class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len2 == 0) return false;
        if (len1 == 0) return true;
        if (len2 < len1) return false;
        vector <int> char1(26, 0), char2(26, 0);
        for (int i = 0; i < len1; i++) {
            char1[s1[i] - 'a']++;
            char2[s2[i] - 'a']++;
        }
        if (char1 == char2) return true;
        for (int i = len1; i < len2; i++) {
            char2[s2[i] - 'a']++;
            char2[s2[i - len1] - 'a']--;
            if (char1 == char2) return true;
        }
        return false;
    }
};
