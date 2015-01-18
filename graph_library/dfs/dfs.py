# Depth First Search

import graph_obj

edgeTo = []
marked = []

def DepthFirstPaths(G, s):
        for i in xrange(G.V()):
                edgeTo.append(-1)
                marked.append(False)

        dfs(G, s)

def dfs(G, v):
        marked[v] = True
        for w in G.adj_vertx(v):
                if (marked[w] == False):
                        dfs(G, w)
                        edgeTo[w] = v

def hasPathto(v):
        return marked[v] == True

def show_path(v):
        path = []
        if (marked[v] == False):
                return None

        while(edgeTo[v] != -1):
                path.insert(0, v)
                v = edgeTo[v]
        path.insert(0, v)

        print(path)


G = graph_obj.Graph(13)
G.add_edge(0, 1)
G.add_edge(0, 2)
G.add_edge(0, 5)
G.add_edge(0, 6)
G.add_edge(6, 4)
G.add_edge(4, 5)
G.add_edge(3, 5)
G.add_edge(3, 4)
G.add_edge(7, 8)
G.add_edge(9, 10)
G.add_edge(9, 11)
G.add_edge(9, 12)
G.add_edge(11, 12)
