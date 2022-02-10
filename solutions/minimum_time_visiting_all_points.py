class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        total_time = 0
        n = len(points)
        for i in range(1, n):
            last_point = points[i - 1]
            curr_point = points[i]
            horizontal_distance = abs(curr_point[0] - last_point[0])
            vertical_distance = abs(curr_point[1] - last_point[1])
            total_time += max(vertical_distance, horizontal_distance)
        return total_time
