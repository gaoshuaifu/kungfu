class Solution(object):
    def licenseKeyFormatting(self, S, K):
        S = S.replace("-", "").upper()
        groups = []
        while S:
            groups.insert(0, S[-K:])
            S = S[:-K]
        return "-".join(groups)
