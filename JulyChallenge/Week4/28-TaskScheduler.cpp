class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> cnt(26, 0);
        int maxcnt = 0, e = 0;
        for (char c : tasks) {
            cnt[c - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            maxcnt = max(maxcnt, cnt[i]);
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == maxcnt) {
                e++;
            }
        }
        return max(len, (maxcnt - 1)*(n + 1) + e);
    }
};
