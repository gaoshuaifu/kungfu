class Solution(object):
    def removeKdigits(self, num, k):
        res = ""
        while k:
            if k == len(num):
                return "0" if res == "" else res

            min_dgt = min(num[:k + 1])
            res += min_dgt
            min_idx = num.find(min_dgt)
            num = num[min_idx + 1:]
            k -= min_idx
        res += num

        i = 0
        while i < len(res) and res[i] == "0":
            i += 1

        return "0" if i == len(res) else res[i:]
