# Dijkstra's algorithm for shortest path

import bag
import min_heap
import digraph

INF = 10000000000000000000000000
edgeTo = []
distTo = []
pq = min_heap.PQ()

def dijkstraSP(G, s):

        for v in xrange(G.V):
                distTo.append(INF)
                edgeTo.append(None)
        distTo[s] = 0.0

        pq.insert(s, 0.0)
        while (not pq.isEmpty()):
                v = pq.delMin()
                for e in G.adjEdges(v):
                        relax(e)

def relax(e):
        v = e.fromV()
        w = e.toV()

        if (distTo[w] > distTo[v] + e.weight()):
                distTo[w] = distTo[v] + e.weight()
                edgeTo[w] = e
                if (pq.contains(w)):
                        pq.decreaseKey(w, distTo[w])
                else:
                        pq.insert(w, distTo[w])

def distance(v):
        return distTo[v]

def pathTo(v):
        stack = []
        e = edgeTo[v]
        while (e != None):
                stack.insert(0, e)
                e = edgeTo[e.fromV()]

        return stack

def show_path(v):
        path = pathTo(v)
        for e in path:
                print(e.v, e.w)



G = digraph.G
dijkstraSP(G, 0)
