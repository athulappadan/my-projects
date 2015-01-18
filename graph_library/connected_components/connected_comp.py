# finding connected components

import graph_obj

marked = []
id_tab = []
counter  = 0

def CC(G):
        global counter

        for i in xrange(G.V()):
                marked.append(False)
                id_tab.append(-1)

        for v in xrange(G.V()):
                if (marked[v] == False):
                        dfs(G, v)
                        counter += 1

def count():
        return counter

def id(v):
        return id_tab[v]

def dfs(G, v):
        marked[v] = True
        id_tab[v] = counter
        for w in G.adj_vertx(v):
                if (marked[w] == False):
                        dfs(G, w)

def isConnected(v, w):
        return id(v) == id(w)


G = graph_obj.Graph(13)
G.add_edge(0, 1)
G.add_edge(0, 2)
G.add_edge(0, 5)
G.add_edge(0, 6)
G.add_edge(5, 3)
G.add_edge(5, 4)
G.add_edge(3, 4)
G.add_edge(4, 6)
G.add_edge(7, 8)
G.add_edge(9, 10)
G.add_edge(9, 11)
G.add_edge(9, 12)
G.add_edge(11, 12)

CC(G)
print(isConnected(0, 9))
print(isConnected(4, 3))

