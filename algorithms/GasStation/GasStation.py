class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        start = 0
        tank, total = 0, 0
        for i in range(len(gas)):
            tank += gas[i] - cost[i]
            total += tank
            if tank < 0:
                tank = 0
                start = i + 1
        return start if total >= 0 else -1
