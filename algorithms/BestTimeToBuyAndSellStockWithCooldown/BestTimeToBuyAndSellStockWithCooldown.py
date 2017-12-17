class Solution(object):
    def maxProfit(self, prices):
        from sys import maxsize

        buy1, buy0 = -maxsize, -maxsize
        sell2, sell1, sell0 = 0, 0, 0

        for price in prices:
            # buy[i] = max(buy[i-1], sell[i-2]-price)
            buy0 = max(buy1, sell2 - price)

            # sell[i] = max(sell[i-1], buy[i-1]+price)
            sell0 = max(sell1, buy1 + price)

            buy1 = buy0
            sell2 = sell1
            sell1 = sell0

        return sell0
