class Solution(object):
    def removeKdigits(self, num, k):
        # Make elements in stk are in increasing order.
        stk = []
        for c in num:
            while k > 0 and stk and stk[-1] > c:
                stk.pop()
                k -= 1
            stk.append(c)
    
        # Continue to remove if less than k elements have been removed.
        while k:
            stk.pop()
            k -= 1
        
        # Remove leading 0s.
        while stk and stk[0] == "0":
            stk.pop(0)
    
        return "".join(stk) if stk else "0"  
        
 
class Solution(object):
    def removeKdigits(self, num, k):
        res = ""
        while k > 0 and k < len(num):
            # In the first k + 1 elements, must keep at least 1, so keep the smallest.
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
