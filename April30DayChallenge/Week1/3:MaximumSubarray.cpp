class Solution {
public:
    int max(int a, int b, int c) {
        int d = ::max(a, b);
        return ::max(c, d);
    }

    int maxCrossingSum(vector<int>& nums, int lo, int mid, int hi) {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= lo; i--) {
            sum += nums[i];
            leftSum = ::max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= hi; i++) {
            sum += nums[i];
            rightSum = ::max(rightSum, sum);
        }
        return leftSum + rightSum;
    }
    int maxSumSubArray(vector<int>& nums, int lo, int hi) {
        if (hi == lo) {
            return nums[lo];
        }
        int mid = (hi + lo)/2;
        int maxSumLeftSubArray = maxSumSubArray(nums, lo, mid);
        int maxSumRightSubArray = maxSumSubArray(nums, mid+1, hi);
        int maxSumCrossingSubArray = maxCrossingSum(nums, lo, mid, hi);
        return max(maxSumLeftSubArray, maxSumRightSubArray, maxSumCrossingSubArray);
    }
    int maxSubArray(vector<int>& nums) {
        return maxSumSubArray(nums, 0, nums.size() - 1);
    }
};
