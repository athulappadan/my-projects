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

        def edges(self):
                return self.edges


e1 = DirectedEdge(0, 1, 5.0)
e2 = DirectedEdge(0, 4, 9.0)
e3 = DirectedEdge(0, 7, 8.0)
e4 = DirectedEdge(1, 2, 12.0)
e5 = DirectedEdge(1, 3, 15.0)
e6 = DirectedEdge(1, 7, 4.0)
e7 = DirectedEdge(2, 3, 3.0)
e8 = DirectedEdge(2, 6, 11.0)
e9 = DirectedEdge(3, 6, 9.0)
e10 = DirectedEdge(4, 5, 4.0)
e11 = DirectedEdge(4, 6, 20.0)
e12 = DirectedEdge(4, 7, 5.0)
e13 = DirectedEdge(5, 2, 1.0)
e14 = DirectedEdge(5, 6, 13.0)
e15 = DirectedEdge(7, 5, 6.0)
e16 = DirectedEdge(7, 2, 7.0)

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
G.addEdge(e16)
