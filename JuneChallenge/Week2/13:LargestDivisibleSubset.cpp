class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<int> dp(n, 0);
        vector<int> last(n, n);
        sort(nums.begin(), nums.end());
        dp[n-1] = 1;
        int maxmGlobl = n-1;
        for (int i = n - 2; i >= 0; i--) { 
            int maxm = i; 
            for (int j = i + 1; j < n; j++) 
                if (nums[j] % nums[i] == 0) 
                    if (dp[j] > dp[maxm]) {
                        maxm = j;
                        last[i] = maxm;
                    }
            dp[i] = 1 + dp[maxm];
            if (dp[i] > dp[maxmGlobl]) {
                maxmGlobl = i;
            }
        }
        vector<int> ans;
        while (last[maxmGlobl] != n) {
            ans.push_back(nums[maxmGlobl]);
            maxmGlobl = last[maxmGlobl];
        }
        ans.push_back(nums[maxmGlobl]);
        return ans;
    }
};

