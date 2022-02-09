class Solution {
public:
    static bool comparator(pair<char, int>  f, pair<char, int>  s) {
        return (f.second > s.second);
    }
    string frequencySort(string s) {
        map<char, int> m;
        for (auto i: s) {
            m[i]++;
        }
        string ans = "";
        vector<pair<char, int>> mv(m.begin(), m.end());
        sort(mv.begin(), mv.end(), comparator);
        for (auto i : mv) {
            for (int j = 0; j < i.second; j++) {
                ans += i.first;
            }
        }
        return ans;
    }
};
