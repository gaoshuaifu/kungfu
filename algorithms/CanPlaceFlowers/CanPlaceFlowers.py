class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        l = len(flowerbed)
        for i in range(l):
            prev = flowerbed[i - 1] if i - 1 >= 0 else 0
            curr = flowerbed[i]
            post = flowerbed[i + 1] if i + 1 < l else 0
            if prev == 0 and curr == 0 and post == 0:
                flowerbed[i] = 1
                n -= 1
        return n <= 0
