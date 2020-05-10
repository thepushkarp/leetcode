class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                nums[zeroCount++] = nums[i];
            }
        }
        while(zeroCount < n) {
            nums[zeroCount++] = 0;
        }
    }
};
