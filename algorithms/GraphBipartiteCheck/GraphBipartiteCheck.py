def graph(graph):
    s1, s2 = set(), set()
    for node, children in graph.items():
        if node in s1:
            if children & s1:
                return False
            s2.extend(children)
        elif node in s2:
            if children & s2:
                return False
            s1.extend(children)
        else:
            s1.add(node)
            s2.extend(children)
    return True
