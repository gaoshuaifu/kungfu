class Solution(object):
    def lexicalOrder(self, n):
        res = []
        curr = 1
        for i in range(n):
            res.append(curr)
            if curr * 10 <= n:
                curr *= 10
            else:
                if curr == n:
                    curr = curr / 10
                curr += 1
                while curr % 10 == 0:
                    curr = curr / 10
        return res

class Solution(object):
    def lexicalOrder(self, n):
        res = []
        curr = 1
        for i in range(n):
            res.append(curr)
            if curr * 10 <= n:
                curr *= 10
            elif curr < n and curr % 10 != 9:
                curr += 1
            else:
                while (curr / 10)  % 10 == 9:
                    curr = curr / 10
                curr = curr / 10 + 1
        return res

class Solution(object):
    def lexicalOrder(self, n):
        res = []
        
        def dfs(curr):
            res.append(curr)
            if curr * 10 <= n:
                dfs(curr * 10)
            if curr + 1 <= n and curr % 10 != 9:
                dfs(curr + 1)
        
        dfs(1)
        return res

