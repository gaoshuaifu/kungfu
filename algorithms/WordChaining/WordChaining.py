class GraphNode(object):
    def __init__(self, name):
        self.name = name
        self.neighbors = []

class Solution(object):
    def __init__(self):
        self.graph = []

    def build_graph(self, names):
        d = {}
        for name in names:
            new_node = GraphNode(name)
            words = name.split(" ")
            for word in words:
                if word not in d:
                    d[word] = [new_node]
                else:
                    for existing_node in d[word]:
                        new_node.neighbors.append(existing_node)
                        existing_node.neighbors.append(new_node)
            self.graph.append(new_node)

    def print_graph(self):
        for node in self.graph:
            name = node.name
            neighbors = [neighbor.name for neighbor in node.neighbors]
            print("%s %s" % (name, neighbors))

def main():
    names = [
        "Julie Tung",
        "Julie Zhou",
        "Zhou Zheng",
        "Wei Zhou",
        "Wei Chen",
        "David Chen",
        "Ping Chen",
        "Ping Li",
    ]

    solution = Solution()
    solution.build_graph(names)
    solution.print_graph()

if __name__ == "__main__":
    main()
