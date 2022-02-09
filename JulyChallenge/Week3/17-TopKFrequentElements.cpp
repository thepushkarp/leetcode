class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<pair<int, int>> v;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        for (auto i : m) {
            v.push_back({i.first, i.second});
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};
