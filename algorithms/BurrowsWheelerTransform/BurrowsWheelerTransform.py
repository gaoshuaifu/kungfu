# https://en.wikipedia.org/wiki/Burrows%E2%80%93Wheeler_transform

EOF = '$'

def bwt_encode(s):
    s += EOF
    words = [s[i:] + s[:i] for i in xrange(len(s))]
    words = sorted(words)
    return ''.join(word[-1] for word in words)

def bwt_decode(s):
    words = [''] * len(s)
    for i in xrange(len(s)):
        words = sorted(s[i] + words[i] for i in xrange(len(s)))
    filtered = [w for w in words if w[-1] == EOF]
    return filtered[0][:-1]


def main():
    s = 'GOGO'
    print(bwt_encode(s))
    print(bwt_decode(bwt_encode(s)))

if __name__ == '__main__':
    main()
