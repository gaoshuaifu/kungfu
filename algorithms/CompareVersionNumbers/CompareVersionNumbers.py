class Solution(object):
    def compareVersion(self, version1, version2):
        list1 = map(int, version1.split('.'))
        list2 = map(int, version2.split('.'))
        l1, l2 = len(list1), len(list2)
        n = max(l1, l2)
        for i in range(n):
            num1 = list1[i] if i < l1 else 0
            num2 = list2[i] if i < l2 else 0
            if num1 > num2:
                return 1
            if num1 < num2:
                return -1
        return 0
