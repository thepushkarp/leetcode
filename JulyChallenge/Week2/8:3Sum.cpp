class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i ++) {
            int j = i + 1;
            int k = n - 1;
            if(nums[i] > 0)
                break;
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j < k and nums[j] == nums[++j]);
                    while (j < k and nums[k] == nums[--k]);
                }
                else if (sum > 0)
                    k--;
                else if (sum < 0)
                    j++;
            }
        }
        return ans;
    }
};

