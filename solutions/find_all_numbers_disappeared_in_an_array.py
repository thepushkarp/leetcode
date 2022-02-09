class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i, num in enumerate(nums):
            if nums[abs(nums[i]) - 1] > 0:
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]
        ans = []
        for i, num in enumerate(nums):
            if nums[i] > 0:
                ans.append(i + 1)
        return ans
