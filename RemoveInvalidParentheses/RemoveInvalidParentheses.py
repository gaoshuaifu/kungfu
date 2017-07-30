# BFS: Level order traverse
class Solution(object):
    def isValid(self, s):
        count = 0
        for c in s:
            if c == '(':
                count += 1
            elif c == ')':
                count -= 1
            if count < 0:
                return False
        return count == 0

    def removeInvalidParentheses(self, s):
        res = set()
        currQ = set()
        currQ.add(s)

        while currQ:
            nextQ = set()
            while currQ:
                node = currQ.pop()

                if self.isValid(node):
                    res.add(node)

                for i in range(len(node)):
                    child = node[:i] + node[i + 1:]
                    nextQ.add(child)

            if res:
                return list(res)
            currQ = nextQ

        return list(res)
