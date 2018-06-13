class Solution(object):
    def removeKdigits(self, num, k):
        res = ""
        while k and k < len(num):
            min_dgt = min(num[:k + 1])
            res += min_dgt
            min_idx = num.find(min_dgt)
            num = num[min_idx + 1:]
            k -= min_idx

        if k == len(num):
            return res if res else "0"

        res = list(res + num)

        while res and res[0] == "0":
            res.pop(0)

        return "".join(res) if res else "0"

s = Solution()
print(s.removeKdigits("789111", 3))
