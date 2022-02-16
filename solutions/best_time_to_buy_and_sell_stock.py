class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n < 2:
            return 0
        max_profit = 0
        buy_price = prices[0]
        for i in range(1, n):
            if prices[i] < buy_price:
                buy_price = prices[i]
            else:
                max_profit = max(max_profit, prices[i] - buy_price)
        return max_profit
