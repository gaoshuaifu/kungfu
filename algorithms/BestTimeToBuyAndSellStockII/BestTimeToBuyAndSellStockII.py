class Solution(object):
    def maxProfit(self, prices):
        n = len(prices)
        profit = 0
        for i in range(1, n):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        return profit

class Solution(object):
    def maxProfit(self, prices):
        from sys import maxsize
        buy = -maxsize
        sell = 0
        for price in prices:
            buy = max(buy, sell - price)
            sell = max(sell, buy + price)
        return sell
