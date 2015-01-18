# weighted graph objects API

import bag

class Edge:
        def __init__(self, v, w, weight):
                self.v = v
                self.w = w
                self.weight = weight

        def either(self):
                return self.v

        def other(self, vertex):
                if (self.v == vertex):
                        return self.w
                else:
                        return self.v

class WeightedGraph:
        def __init__(self, V):
                self.V = V
                self.adj = []
                self.edges = []
                for v in xrange(V):
                        new = bag.Bag()
                        self.adj.append(new)

        def addEdge (self, e):
                v = e.either()
                w = e.other(v)
                self.adj[v].add(e)
                self.adj[w].add(e)
                self.edges.append(e)

        def edge(self, v):
                return self.adj[v].iter_bag()

        def allEdges(self):
                return self.edges

class MST:
        def __init__(self):
                self.tab = []

        def size(self):
                return len(self.tab)

        def push_edge(self, e):
                self.tab.append(e)

        def edges(self):
                for e in self.tab:
                        yield e

G = WeightedGraph(8)
e3 = Edge(1, 7, 0.19)
e4 = Edge(0, 2, 0.26)
e5 = Edge(5, 7, 0.28)
e1 = Edge(0, 7, 0.16)
e2 = Edge(2, 3, 0.17)
e6 = Edge(1, 3, 0.29)
e7 = Edge(1, 5, 0.32)
e8 = Edge(2, 7, 0.34)
e9 = Edge(4, 5, 0.35)
e10 = Edge(1, 2, 0.36)
e16 = Edge(6, 4, 0.93)
e15 = Edge(6, 0, 0.58)
e14 = Edge(3, 6, 0.52)
e13 = Edge(6, 2, 0.40)
e12 = Edge(0, 4, 0.38)
e11 = Edge(4, 7, 0.37)

G.addEdge(e3)
G.addEdge(e4)
G.addEdge(e5)
G.addEdge(e1)
G.addEdge(e2)
G.addEdge(e6)
G.addEdge(e7)
G.addEdge(e8)
G.addEdge(e9)
G.addEdge(e10)
G.addEdge(e16)
G.addEdge(e15)
G.addEdge(e14)
G.addEdge(e13)
G.addEdge(e12)
G.addEdge(e11)
