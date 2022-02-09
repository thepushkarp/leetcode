class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        xor = 0
        for c in s:
            xor ^= ord(c)
        for c in t:
            xor ^= ord(c)
        return chr(xor)
