class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> ransomCount;
        for (auto i: ransomNote) {
            ransomCount[i]++;
        }
        for (auto i : magazine) {
            if (ransomCount[i]) ransomCount[i]--;
        }
        for (auto i : ransomNote) {
            if (ransomCount[i]) {
                return false;
            }
        }
        return true;
    }
};
