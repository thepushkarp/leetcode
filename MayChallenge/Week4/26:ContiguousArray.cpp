class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;
        map<int, vector<int>> m;
        m[0].push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) sum++; else sum--;
            m[sum].push_back(i);
        }
        int maxLen = 0;
        for (auto j : m) {
            vector<int> i = j.second;
            maxLen = max(maxLen, *max_element(i.begin(), i.end()) - *min_element(i.begin(), i.end()));
        }
        return maxLen;
    }
};
