class Solution(object):
    def maxProfit(self, prices, fee):
        from sys import maxsize
        buy = -maxsize
        sell = 0
        for price in prices:
            buy = max(buy, sell - price)
            sell = max(sell, buy + price - fee)
        return sell
