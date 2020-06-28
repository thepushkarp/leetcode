class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unsigned int ans = 0, bit, sum;

        for (int i = 0; i < 32; i++) {
            sum = 0;
            bit = (1 << i);
            for (int j = 0; j < n; j++) {
                if (nums[j] & bit) {
                    sum++;
                }
            }
            if (sum % 3) {
                ans |= bit;
            }
        }
        return ans;
    }
};
