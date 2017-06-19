class Solution(object):
    def tree2str(self, t):
        if not t:
            return ''
        left = '({})'.format(self.tree2str(t.left)) if (t.left or t.right) else ''
        right = '({})'.format(self.tree2str(t.right)) if t.right else ''
        return '{}{}{}'.format(t.val, left, right)


class Solution(object):
    def tree2str_helper(self, t, res):
        res.append(str(t.val))

        if t.left:
            res.append('(')
            self.tree2str_helper(t.left, res)
            res.append(')')
        elif t.right:
            res.append('()')

        if t.right:
            res.append('(')
            self.tree2str_helper(t.right, res)
            res.append(')')

    def tree2str(self, t):
        if not t:
            return ''
        res = []
        self.tree2str_helper(t, res)
        return ''.join(res)
