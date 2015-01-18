# edge weighted digraph API

import bag

class DirectedEdge:
        def __init__(self, v, w, wt):
                self.v = v
                self.w = w
                self.wt = wt

        def fromV(self):
                return self.v

        def toV(self):
                return self.w

        def weight(self):
                return self.wt


class EdgeWeightedDigraph:
        def __init__(self, V):
                self.V = V
                self.adj = []
                self.edges = []
                for v in xrange(self.V):
                        new = bag.Bag()
                        self.adj.append(new)

        def addEdge(self, e):
                v = e.fromV()
                self.adj[v].add(e)
                self.edges.append(e)

        def adjEdges(self, v):
                return self.adj[v].iter_bag()

        def allEdges(self):
                return self.edges

e1 = DirectedEdge(4, 5, 0.35)
e2 = DirectedEdge(5, 4, 0.16)
e3 = DirectedEdge(4, 7, 0.37)
e4 = DirectedEdge(5, 7, 0.28)
e5 = DirectedEdge(7, 5, 0.28)
e6 = DirectedEdge(5, 1, 0.32)
e7 = DirectedEdge(0, 4, 0.38)
e8 = DirectedEdge(0, 2, 0.26)
e9 = DirectedEdge(7, 3, 0.39)
e10 = DirectedEdge(1, 3, 0.29)
e11 = DirectedEdge(2, 7, 0.34)
e12 = DirectedEdge(6, 2, 0.40)
e13 = DirectedEdge(3, 6, 0.52)
e14 = DirectedEdge(6, 0, 0.58)
e15 = DirectedEdge(6, 4, 0.93)

G = EdgeWeightedDigraph(8)
G.addEdge(e1)
G.addEdge(e2)
G.addEdge(e3)
G.addEdge(e4)
G.addEdge(e5)
G.addEdge(e6)
G.addEdge(e7)
G.addEdge(e8)
G.addEdge(e9)
G.addEdge(e10)
G.addEdge(e11)
G.addEdge(e12)
G.addEdge(e13)
G.addEdge(e14)
G.addEdge(e15)
