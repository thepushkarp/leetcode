class Solution:
    def fib(self, n: int) -> int:
        if n < 2:
            return n
        first = 0
        second = 1
        for i in range(2, n + 1):
            second = first + second
            first = second - first
        return second
