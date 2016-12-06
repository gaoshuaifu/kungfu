
def dlca(root):
    def dlca_helper(root):
        lca = root
        max_depth = 0  # max depth of root's subtrees
        for child in root.children:
            (child_lca, child_depth) = dlca_helper(child)
            if child_depth > max_depth:
                lca = child_lca
                max_depth = child_depth
            elif child_depth == max_depth:
                lca = root
        return lca, max_depth + 1
    return dlca_helper(root)[0]
