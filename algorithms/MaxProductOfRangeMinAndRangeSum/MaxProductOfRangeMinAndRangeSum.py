class Solution(object):
    def max_product_of_range_min_and_range_sum(self, nums):
        n = len(nums)

        # The accumulative sum. The sum in range i...j can be calculated as 
        # accu_sum[j] - accu_sum[i - 1] if i > 0 else accu_sum[j]
        accu_sums = [0] * n
        accu_sum = 0
        for i in range(n):
            accu_sum += nums[i];
            accu_sums[i] = accu_sum

        # The monotone stack. The elements in the stack are in increasing order.
        stk = []

        # From left to right
        left = [0] * n
        for i in range(n):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()

            if stk:
                left[i] = stk[-1] + 1
            else:
                left[i] = 0

            stk.append(i)

        stk = []

        # From right to left
        right = [0] * n
        for i in range(n - 1, -1, -1):
            while stk and nums[stk[-1]] >= nums[i]:
                stk.pop()

            if stk:
                right[i] = stk[-1] - 1
            else:
                right[i] = n - 1
            stk.append(i)
            
        # Take each element as min, find out the range and calculate product.
        max_product = 0
        for i in range(n):
            range_min = nums[i]
            
            # Get range sum based on accumulative sum and range index
            left_idx, right_idx = left[i], right[i]
            range_sum = accu_sums[right_idx] - accu_sums[left_idx - 1] if left_idx > 0 else accu_sums[right_idx]
            
            max_product = max(max_product, range_min * range_sum)

        return max_product

s = Solution()
print(s.max_product_of_range_min_and_range_sum([1, 2, 6]))
print(s.max_product_of_range_min_and_range_sum([6, 2, 5, 5, 5, 4, 7]))

