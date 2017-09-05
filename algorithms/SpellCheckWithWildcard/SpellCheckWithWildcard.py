
def findMatch(trie, word):
    return findMatchHelper(trie, trie.getRoot(), word, 0)

def findMatchHelper(trie, node, word, index):
    if index == len(word)
        # if we're at the end of the word
        return trie.isTerminalNode(node)

    let = word[index]
    if let == '*':
        # wildcard character: search each child of this node
        for child in trie.getAllChildren(node):
            if findMatchHelper(trie, child, word, index + 1):
                return True
        return False

    else:
        child = trie.getChild(node, let)
        if child == None:
            # this node doesn't contain the child we're looking for, so the word is not here
            return False
        return findMatchHelper(trie, child, word, index + 1)
