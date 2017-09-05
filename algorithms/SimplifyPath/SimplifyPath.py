class Solution(object):
    def simplifyPath(self, path):
        tokens = path.split('/')
        simple_tokens = []
        for token in tokens:
            if token == '..' and simple_tokens:
                simple_tokens.pop()
            elif token != '..' and token != '.' and token:
                simple_tokens.append(token)
        return '/' + '/'.join(simple_tokens)

if __name__ == '__main__':
    path = '/./home///ywang/../ywang/.profile/programming'
    solution = Solution()
    print(solution.simplifyPath(path))
