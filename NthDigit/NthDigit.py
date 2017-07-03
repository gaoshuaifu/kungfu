class Solution(object):
    def findNthDigit(self, n):
        length, count, start = 1, 9, 1
        while n > length * count:
            n -= length * count
            length += 1
            count *= 10
            start *= 10
        num = start + (n - 1) / length
        return int(list(str(num))[(n - 1) % length])
