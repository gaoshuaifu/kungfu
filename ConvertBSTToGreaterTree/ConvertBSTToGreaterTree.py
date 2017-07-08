class Solution(object):
    def convertBST(self, root):
        stk, curr, sum_so_far = [], root, 0
        while curr or stk:
            if curr:
                stk.append(curr)
                curr = curr.right
            else:
                node = stk.pop()
                node.val += sum_so_far
                sum_so_far = node.val
                curr = node.left
        return root
