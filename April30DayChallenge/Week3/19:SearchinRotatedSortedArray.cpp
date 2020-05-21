class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return target==nums[0]?0:-1;
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            if (target == nums[mid]) return mid;
            if (nums[lo] <= nums[mid]) {
                if (target >= nums[lo] and target <= nums[mid]) {
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
            else {
                if (target >= nums[mid] and target <= nums[hi]) {
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
        }
        return -1;
    }
};
