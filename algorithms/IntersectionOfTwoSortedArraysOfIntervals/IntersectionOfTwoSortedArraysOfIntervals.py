# general formula to get intersection of two intervals
def intersect(a, b):
    left = max(a[0], b[0])
    right = min(a[1], b[1])
    return (left, right) if left < right else None


# Time Complexity: O(M + N)
def intersections(A, B):
    result = []
    i, j = 0, 0
    while i < len(A) and j < len(B):
        c = intersect(A[i], B[j])
        if c is not None:
            result.append(c)
        if A[i][1] < B[j][1]:
            i += 1
        else:
            j += 1
    return result
