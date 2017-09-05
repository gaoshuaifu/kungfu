class Solution(object):
    def findMode(self, root):
        res, stk = [], []
        prev_val, curr = None, root
        freq, max_freq = 0, 0

        while curr or stk:
            if curr:
                stk.append(curr)
                curr = curr.left
            else:
                curr = stk.pop()

                if curr.val == prev_val:
                    freq += 1
                else:
                    freq = 1

                if freq == max_freq:
                    res.append(curr.val)
                elif freq > max_freq:
                    max_freq = freq
                    res = [curr.val]

                prev_val = curr.val

                curr = curr.right

        return res
