class Solution(object):

    def __init__(self, head):
        self.head = head

    def getRandom(self):
        import random
        res = self.head.val
        node = self.head.next
        count = 1
        while node:
            r = random.randint(0, count)
            if r == 0:
                res = node.val
            count += 1
            node = node.next
        return res
