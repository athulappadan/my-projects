# Weighted Quick Union with path compression

idTab = []
sz    = []

def QuickUnionUF(N):
        for i in xrange(N):
                idTab.append(i)
                sz.append(1)

def  root(i):
        while (i != idTab[i]):
                idTab[i] = idTab[idTab[i]]
                i = idTab[i]
        return i

def connected(p, q):
        return root(p) == root(q)

def union(p, q):
        i = root(p)
        j = root(q)
        if (i == j): return
        if (sz[i] < sz[j]):
                idTab[i] = j
                sz[j] += sz[i]
        else:
                idTab[j] = i
                sz[i] += sz[j]


QuickUnionUF(10)
union(3, 5)
union(8, 5)
union(7, 6)
union(1, 2)
union(1, 4)
union(0, 9)
union(4, 9)

