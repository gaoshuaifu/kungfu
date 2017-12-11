class Solution(object):
    def unique_perm(self, s, index, perms):
        if index == len(s):
            perms.append("".join(s))

        visited = set()

        for i in range(index, len(s)):
            if s[i] not in visited:
                visited.add(s[i])
                s[i], s[index] = s[index], s[i]
                self.unique_perm(s, index + 1, perms)
                s[i], s[index] = s[index], s[i]

    def generatePalindromes(self, s):
        from collections import Counter
        counter = Counter(s)
        mid, base_str = "", []
        for char, count in counter.items():
            if count % 2 == 1:
                if mid:
                    return []
                mid = char
            base_str += [char] * (count / 2)

        perms = []
        self.unique_perm(base_str, 0, perms)
        return [p + mid + p[::-1] for p in perms]
