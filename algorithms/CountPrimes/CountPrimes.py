# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
class Solution(object):
    def countPrimes(self, n):
        if n < 2:
            return 0
        prime = [True] * n
        prime[0], prime[1] = False, False
        for i in range(2, int(n ** 0.5) + 1):
            if prime[i]:
                for j in range(i ** 2, n, i):
                    prime[j] = False
        return sum(prime)
