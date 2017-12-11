class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.

        :type strs: List[str]
        :rtype: str
        """

        encoded = ""
        for s in strs:
            encoded += "{}/{}".format(len(s), s)
        return encoded

    def decode(self, s):
        """Decodes a single string to a list of strings.

        :type s: str
        :rtype: List[str]
        """

        decoded, start = [], 0
        while start < len(s):
            slash = s.find("/", start)
            length = int(s[start:slash])
            decoded.append(s[slash + 1: slash + length + 1])
            start = slash + length + 1
        return decoded
