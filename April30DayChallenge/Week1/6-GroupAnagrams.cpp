class Solution {
public:
    map<char, int> mapString(string str) {
        map<char, int> m;
        for (auto i : str) {
            m[i]++;
        }
        return m;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> grp;
        vector<map<char, int>> m;
        for (auto i : strs) {
            map<char, int> strMap = mapString(i);
            auto pos  = find(m.begin(), m.end(), strMap);
            if (pos != m.end()) {
                int index = distance(m.begin(), pos);
                grp[index].push_back(i);
            }
            else {
                m.push_back(strMap);
                vector<string> v;
                v.push_back(i);
                grp.push_back(v);
            }
        }
        return grp;
    }
};
