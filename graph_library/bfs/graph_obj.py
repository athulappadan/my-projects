# graph object using bag

import bag

class Graph():
        def __init__(self, V):
                self.adj_list = []
                self.edges = 0
                for i in xrange(V):
                        new_list = bag.Bag()
                        self.adj_list.append(new_list)

        def add_edge(self, v, w):
                self.adj_list[v].add(w)
                self.adj_list[w].add(v)
                self.edges += 1

        def adj_vertx(self, v):
                return self.adj_list[v].iter_bag()

        def V(self):                        # no. of vertices
                return len(self.adj_list)

        def E(self):                        # no. of edges
                return self.edges

        def degree(self, v):                      # degree of vertex v
                degree = 0
                for w in self.adj_vertx(v):
                        degree += 1
                return degree

