import copy
class Solution(object):
    def findSubsequencesHelper(self, nums, start, sol, res):    
        if len(sol) >= 2:
            res.append(copy.deepcopy(sol))
        
        visited = set()
        for i in range(start, len(nums)):
            if nums[i] not in visited and (not sol or sol[-1] <= nums[i]):
                visited.add(nums[i])
                sol.append(nums[i])
                self.findSubsequencesHelper(nums, i + 1, sol, res)
                sol.pop()
        
    def findSubsequences(self, nums):
        sol, res = [], []
        self.findSubsequencesHelper(nums, 0, sol, res)
        return res


class Solution(object):
    def findSubsequences(self, nums):
        S = set()
        for num in nums:
            T = set()
            for x in S:
                if x[-1] <= num:
                    T.add(x + tuple([num]))
            S = S.union(T)
            S.add(tuple([num]))
        return [list(x) for x in S if len(x) > 1]
