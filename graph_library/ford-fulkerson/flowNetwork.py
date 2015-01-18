from flowedge import *
import bag

class FlowNetwork:
        def __init__(self, V):
                self.V = V
                self.adj = []
                self.edges = bag.Bag()
                for v in xrange(V):
                        new = bag.Bag()
                        self.adj.append(new)

        def addEdge(self, e):
                v = e.fromV()
                w = e.toV()
                self.adj[v].add(e)
                self.adj[w].add(e)
                self.edges.add(e)

        def adjEdges(self, v):
                return self.adj[v].iter_bag()

        def allEdges(self):
                return self.edges.iter_bag()


G = FlowNetwork(6)
G.addEdge(e1)
G.addEdge(e2)
G.addEdge(e3)
G.addEdge(e4)
G.addEdge(e5)
G.addEdge(e6)
G.addEdge(e7)
G.addEdge(e8)

