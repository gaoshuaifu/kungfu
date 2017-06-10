# http://blog.csdn.net/xudli/article/details/46798619
# http://www.cnblogs.com/grandyang/p/4629032.html
class Solution(object):
    def countDigitOne(self, n):
        ones = 0
        k = 1
        while k <= n:
            a, b = divmod(n, k)
            ones += (a + 8) / 10 * k + (a % 10 == 1) * (b + 1)
            k *= 10
        return ones
