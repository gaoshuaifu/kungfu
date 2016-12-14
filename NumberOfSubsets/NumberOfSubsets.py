# Find the number of non-empty subsets S such that min(S) + max(S) <= K

def numsOfSubsets(a, k):
    a.sort()

    i = 0
    j = len(a) - 1
    res = 0
    while(i <= j):
        while(a[i] + a[j] > k):
            j -= 1
        res += 2 ** (j - i)
        i += 1
    return res

if __name__ == '__main__':
    a = [2, 4, 5, 7]
    k = 8
    print(numsOfSubsets(a, k))
