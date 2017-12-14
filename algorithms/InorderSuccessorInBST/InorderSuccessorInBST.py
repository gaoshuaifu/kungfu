class Solution(object):
    def inorderSuccessor(self, root, p):
        succ = None
        while root:
            if root.val <= p.val:
                root = root.right
            else:
                succ = root
                root = root.left
        return succ


class Solution(object):
    def inorderSuccessor(self, root, p):
        prev, curr = None, root
        stk = []
        while curr or stk:
            if curr:
                stk.append(curr)
                curr = curr.left
            else:
                curr = stk.pop()
                if prev == p:
                    return curr
                prev = curr
                curr = curr.right
        return None
