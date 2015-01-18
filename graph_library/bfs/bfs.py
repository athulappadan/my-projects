# Breadth First algorithm

import graph_obj

marked = []
edgeTo = []

def BreadthFirstPaths(G, s):
        for i in xrange(G.V()):
                marked.append(False)
                edgeTo.append(-1)
        bfs(G, s)

def bfs(G, s):
        q = []
        q.append(s)
        marked[s] = True

        while (len(q) != 0):
                v = q.pop(0)

                for w in G.adj_vertx(v):
                        if (marked[w] == False):
                                q.append(w)
                                marked[w] = True
                                edgeTo[w] = v

def hasPath(v):
        return marked[v] == True

def show_path(v):
        path = []
        if (marked[v] == False):
                return None

        while (edgeTo[v] != -1):
                path.insert(0, v)
                v = edgeTo[v]
        path.insert(0, v)

        print(path)


G = graph_obj.Graph(6)
G.add_edge(0, 1)
G.add_edge(0, 2)
G.add_edge(0, 5)
G.add_edge(1, 2)
G.add_edge(2, 3)
G.add_edge(2, 4)
G.add_edge(3, 4)
G.add_edge(3, 5)
