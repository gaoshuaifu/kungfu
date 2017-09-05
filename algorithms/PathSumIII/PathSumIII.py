class Solution(object):
    def pathSumHelper(self, root, target, sum_so_far, pre_sum):
        if not root:
            return 0

        sum_so_far += root.val
        if (sum_so_far - target) in pre_sum:
            self.res += pre_sum[sum_so_far - target]

        pre_sum[sum_so_far] += 1
        self.pathSumHelper(root.left, target, sum_so_far, pre_sum)
        self.pathSumHelper(root.right, target, sum_so_far, pre_sum)
        pre_sum[sum_so_far] -= 1


    def pathSum(self, root, target):
        # key: prefix sum => value: the number of ways get to the prefix sum
        from collections import defaultdict
        pre_sum = defaultdict(int)
        pre_sum[0] = 1

        self.res = 0
        self.pathSumHelper(root, target, 0, pre_sum)
        return self.res
