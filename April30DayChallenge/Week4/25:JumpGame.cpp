class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 0) return true;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= n) n = i;
        }
        return n == 0;
    }
};
