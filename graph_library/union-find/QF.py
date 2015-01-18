#simple QuickFind algorithm

idTab = []

def QuickFindUF(N):
        for i in xrange(N):
                idTab.append(i)

def connected(p, q):
        return idTab[p] == idTab[q]

def union(p, q):
        pid = idTab[p]
        qid = idTab[q]
        for i in xrange(len(idTab)):
                if (idTab[i] == pid):
                        idTab[i] = qid

QuickFindUF(10)
union(4, 3)
union(9, 8)
union(3, 9)
union(7, 1)
