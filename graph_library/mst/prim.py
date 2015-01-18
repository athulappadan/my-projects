# Prim's algorithm - lazy implementation

import mst
import min_heap

pq = min_heap.PQ()
prim_mst = mst.MST()
marked = []

def LazyPrimMST(G):
        for i in xrange(G.V):
                marked.append(False)

        visit(G, 0)

        while (not pq.isEmpty()):
                e = pq.delMin()
                v = e.either()
                w = e.other(v)

                if (not (marked[v] and marked[w])):
                        prim_mst.push_edge(e)
                        if (not marked[v]): visit(G, v)
                        if (not marked[w]): visit(G, w)

        return prim_mst

def visit(G, v):
        marked[v] = True
        for e in G.edge(v):
                if (not marked[e.other(v)]):
                        pq.insert(e)


def show_mst(prim):
        for e in prim.edges():
                print(e.v, e.w, e.weight)

G = mst.G
prim = LazyPrimMST(G)
show_mst(prim)
