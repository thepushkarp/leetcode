class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> j;
        for (auto i : J) {
            j.insert(i);
        }
        long count = 0;
        for (auto i : S) {
            if (j.find(i) != j.end()) count++;
        }
        return count;
    }
};
