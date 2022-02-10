class Solution:
    def tribonacci(self, n: int) -> int:
        if n < 2:
            return n
        if n == 2:
            return 1
        first = 0
        second = 1
        third = 1
        for i in range(3, n + 1):
            third = third + second + first
            second = third - second - first
            first = third - second - first
        return third
