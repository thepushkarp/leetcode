class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        contains_dup = False
        seen = dict()
        for i, num in enumerate(nums):
            val = seen.get(num, -1)
            if val == -1:
                seen[num] = i
            elif abs(val - i) <= k:
                contains_dup = True
                break
            else:
                seen[num] = i
        return contains_dup
