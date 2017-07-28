class Solution(object):
    def isInt10(self, num):
        try:
            int(num)
            return True
        except ValueError:
            return False

    def isInt16(self, num):
        try:
            int(num, 16)
            return True
        except ValueError:
            return False

    def isIPv4Num(self, num):
        if not self.isInt10(num) or num[0] == "-" or int(num) > 255 or (num[0] == "0" and len(num) > 1):
            return False
        return True

    def isIPv4(self, IP):
        nums = IP.split(".")
        return (
            len(nums) == 4 and
            all([self.isIPv4Num(num) for num in nums])
        )

    def isIPv6Num(self, num):
        return len(num) > 0 and len(num) <= 4 and self.isInt16(num) and num[0] != "-"

    def isIPv6(self, IP):
        nums = IP.split(":")
        return (
            len(nums) == 8 and
            all([self.isIPv6Num(num) for num in nums])
        )

    def validIPAddress(self, IP):
        if self.isIPv4(IP):
            return "IPv4"
        elif self.isIPv6(IP):
            return "IPv6"
        return "Neither"
