class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.is_terminal = False
        self.kids = [None] * 26

    def get_kid(self, val):
        return self.kids[ord(val) - ord("a")]

    def set_kid(self, val):
        self.kids[ord(val) - ord("a")] = TreeNode(val)

class WordDictionary(object):

    def __init__(self):
        self.root = TreeNode("")

    def addWord(self, word):

        if self.search(word):
            return

        curr = self.root
        for c in word:
            if not curr.get_kid(c):
                curr.set_kid(c)
            curr = curr.get_kid(c)
        curr.is_terminal = True

    def _search_helper(self, node, word, index):
        if index == len(word):
            return node.is_terminal

        c = word[index]
        if c != ".":
            kid = node.get_kid(c)
            if not kid:
                return False
            return self._search_helper(kid, word, index + 1)
        else:
            for kid in node.kids:
                if kid and self._search_helper(kid, word, index + 1):
                    return True
            return False

    def search(self, word):
        return self._search_helper(self.root, word, 0)
