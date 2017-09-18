class NumArray(object):

    def __init__(self, nums):
        self.nums = nums

    def update(self, i, val):
        self.nums[i] = val

    def sumRange(self, i, j):
        return sum(self.nums[i:j+1])
        
