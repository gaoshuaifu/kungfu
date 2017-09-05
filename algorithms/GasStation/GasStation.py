class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        start, tank, total = 0, 0, 0
        for i in range(len(gas)):
            tank += gas[i] - cost[i]
            if tank < 0:
                total += tank
                tank = 0
                start = i + 1
        total += tank
        return start if total >= 0 else -1
