# A bulb ends up on iff it has an odd number of divisors (switched an odd number of times).
# Only square number has odd number of divisors.
class Solution(object):
    def bulbSwitch(self, n):
        return int(n ** 0.5)
