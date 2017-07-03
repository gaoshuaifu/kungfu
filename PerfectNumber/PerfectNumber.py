class Solution(object):
    def checkPerfectNumber(self, num):
        if num <= 0:
            return False
        s, i = 0, 1
        while i * i <= num:
            if num % i == 0:
                s += i
                if i * i != num:
                    s += num / i
            i += 1
        s -= num
        return s == num
