from copy import deepcopy
from random import randint

class Solution(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.original = nums


    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        
        return self.original


    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        
        nums = deepcopy(self.original)
        n = len(nums)

        # go through 0...(n - 1)
        for i in range(n):
            # generate random number between i...(n - 1)
            r = randint(i, n - 1)
            nums[i], nums[r] = nums[r], nums[i]
        
        return nums
