# http://blog.csdn.net/xudli/article/details/46798619
# http://www.cnblogs.com/grandyang/p/4629032.html

# intuitive: 每10个数, 有一个个位是1, 每100个数, 有10个十位是1, 每1000个数, 有100个百位是1.  做一个循环, 每次计算单个位上1得总个数(个位,十位, 百位).
# 例子:
# 以算百位上1为例子:   假设百位上是0, 1, 和 >=2 三种情况:
#     case 1: n=3141092, a= 31410, b=92. 计算百位上1的个数应该为 3141 *100 次.
#     case 2: n=3141192, a= 31411, b=92. 计算百位上1的个数应该为 3141 *100 + (92+1) 次.
#     case 3: n=3141592, a= 31415, b=92. 计算百位上1的个数应该为 (3141+1) *100 次.
# 以上三种情况可以用 一个公式概括:
# (a + 8) / 10 * m + (a % 10 == 1) * (b + 1)
class Solution(object):
    def countDigitOne(self, n):
        ones = 0
        k = 1
        while k <= n:
            a, b = divmod(n, k)
            ones += (a + 8) / 10 * k + (a % 10 == 1) * (b + 1)
            k *= 10
        return ones
