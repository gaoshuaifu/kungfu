class Solution(object):
    def decodeString(self, s):
        res = ""
        for c in s:
            if c == "]":
                # Find the encoded string
                j = res.rfind("[")
                sub = res[j + 1:]

                # Find the num
                i = j - 1
                while res[i].isdigit():
                    i -= 1
                num = int(res[i + 1: j])

                # decode
                res = res[:i + 1] + num * sub
            else:
                res += c
        return res
