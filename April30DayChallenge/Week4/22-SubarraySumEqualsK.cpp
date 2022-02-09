class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map <int, int> sums;
        int temp = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            temp += nums[i];
            if (temp == k) ans++;
            if(sums.find(temp - k) != sums.end()) {
                ans += sums[temp - k];
            }
            sums[temp]++;
        }
        return ans;
    }
};
