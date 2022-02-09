class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subSize = pow(2, n);
        vector<vector<int>> ans(subSize);
        for (int i = 0; i < subSize; i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};

