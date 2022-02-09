class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        n = len(nums)
        width = t + 1
        buckets = {}
        for i, num in enumerate(nums):
            bucket = num // width
            if bucket in buckets:
                return True
            else:
                buckets[bucket] = num
                if bucket - 1 in buckets and num - buckets[bucket - 1] <= t:
                    return True
                if bucket + 1 in buckets and buckets[bucket + 1] - num <= t:
                    return True
                if i >= k:
                    del buckets[nums[i - k] // width]
        return False
