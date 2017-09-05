class Codec:
    def __init__(self):
        import string

        # 62 chars ["0",...,"9","a",...,"z","A",...,"Z"]
        self.ALPHABETA = map(str, range(10)) + list(string.ascii_letters)
        # char => index
        self.MAP = {c:i for i, c in enumerate(self.ALPHABETA)}
        # 62
        self.BASE = len(self.ALPHABETA)
        # The initial id
        self.id = 100000
        # the map between id and long url
        self.d = {}

    def _int2str(self, n):
        s = ""
        while n:
            n, d = divmod(n, self.BASE)
            s += self.ALPHABETA[d]
        return s[::-1]

    def _str2int(self, s):
        n = 0
        base = 1
        for c in s[::-1]:
            n += self.MAP[c] * base
            base *= self.BASE
        return n

    def encode(self, longUrl):
        s = self._int2str(self.id)
        self.d[self.id] = longUrl
        self.id += 1
        return "http://tinyurl.com/{}".format(s)


    def decode(self, shortUrl):
        s = shortUrl.split("/")[-1]
        return self.d[self._str2int(s)]
