class Solution(object):
    def maxProfit(self, prices):
        from sys import maxsize
        buy1, sell1, buy2, sell2 = -maxsize, 0, -maxsize, 0
        for price in prices:
            buy1 = max(buy1, -price)
            sell1 = max(sell1, buy1 + price)
            buy2 = max(buy2, sell1 - price)
            sell2 = max(sell2, buy2 + price)
        return sell2
