class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        row = ord(coordinates[0]) - 97 + 1
        column = int(coordinates[1])
        if (row + column) % 2:
            return True
        return False
