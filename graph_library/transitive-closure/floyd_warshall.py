from digraph import *

NegativeCycle = False
distTo = []
edgeTo = []

def FloydWarshall(G):
        V = G.V
        for v in xrange(V):
                dist = []
                edge = []
                for w in xrange(V):
                        dist.append(float("inf"))
                        edge.append(None)
                distTo.append(dist)
                edgeTo.append(edge)

        for v in xrange(V):
                for e in G.adjEdges(v):
                        distTo[e.fromV()][e.toV()] = e.weight()
                        edgeTo[e.fromV()][e.toV()] = e

                if (distTo[v][v] >= 0.0):
                        distTo[v][v] = 0.0
                        edgeTo[v][v] = None

        for i in xrange(V):
                for v in xrange(V):
                        if (edgeTo[v][i] == None): continue
                        for w in xrange(V):
                                if (distTo[v][w] > distTo[v][i] + distTo[i][w]):
                                        distTo[v][w] = distTo[v][i] + distTo[i][w]
                                        edgeTo[v][w] = edgeTo[i][w]

                if (distTo[v][v] < 0.0):
                        NegativeCycle = True
                        return


def hasNegativeCycle():
        return NegativeCycle

def hasPath(s, t):
        return distTo[s][t] < float("inf")

def dist(s, t):
        if (hasNegativeCycle()):
               raise Exception("Negative cost cycle exists")
        return distTo[s][t]

def path(s, t):
        if (hasNegativeCycle()):
               raise Exception("Negative cost cycle exists")
        if (not hasPath(s, t)):
                return None
        path = []
        e = edgeTo[s][t]
        while (e != None):
                path.append(e)
                e = edgeTo[s][e.fromV()]

        return path

FloydWarshall(G)
