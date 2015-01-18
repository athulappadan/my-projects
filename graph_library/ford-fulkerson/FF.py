import flowNetwork

marked = []
edgeTo = []
value = 0.0

for v in xrange(flowNetwork.G.V):
        marked.append(False)
        edgeTo.append(-1)

def FordFulkerson(G, s, t):
        global value
        value = 0.0
        while (hasAugmentingPath(G, s, t)):
                bottle = float("inf")
                v = t
                while (v != s):
                        bottle = min(bottle, edgeTo[v].residualCapacityTo(v))
                        v = edgeTo[v].other(v)

                v = t
                while (v != s):
                        edgeTo[v].addResidualFlowTo(v, bottle)
                        v = edgeTo[v].other(v)

                value += bottle

def hasAugmentingPath(G, s, t):
        for v in xrange(G.V):
               edgeTo[v] = -1
               marked[v] = False

        q = []
        q.insert(0, s)
        marked[s] = True
        while (len(q)):
                v = q.pop()

                for e in G.adjEdges(v):
                        w = e.other(v)

                        if (e.residualCapacityTo(w) > 0 and not marked[w]):
                                edgeTo[w] = e
                                marked[w] = True
                                q.insert(0, w)

        return marked[t]

def value():
        return value

def inCut(v):
        return marked[v]

G = flowNetwork.G
FordFulkerson(G, 0, 5)
