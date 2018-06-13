class Solution(object):
    def pathSumHelper(self, root, target, sum_from_root, pre_sum):
        if not root:
            return 

        sum_from_root += root.val
        if (sum_from_root - target) in pre_sum:
            self.count += pre_sum[sum_from_root - target]

        pre_sum[sum_from_root] += 1
        self.pathSumHelper(root.left, target, sum_from_root, pre_sum)
        self.pathSumHelper(root.right, target, sum_from_root, pre_sum)
        pre_sum[sum_from_root] -= 1


    def pathSum(self, root, target):
        # key: prefix sum
        # val: the number of prefix sum
        from collections import defaultdict
        pre_sum = defaultdict(int)
        pre_sum[0] = 1

        self.count = 0
        self.pathSumHelper(root, target, 0, pre_sum)
        return self.count
