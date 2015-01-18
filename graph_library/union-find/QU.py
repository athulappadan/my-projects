# simple Quick Union implementation

idTab = []

def QuickUnionUF(N):
        for i in xrange(N):
                idTab.append(i)

def  root(i):
        while (i != idTab[i]):
                i = idTab[i]
        return i

def connected(p, q):
        return root(p) == root(q)

def union(p, q):
        i = root(p)
        j = root(q)
        idTab[i] = j


QuickUnionUF(10)
union(3, 5)
union(8, 5)
union(7, 6)
union(1, 2)
union(1, 4)
union(0, 9)
union(4, 9)

