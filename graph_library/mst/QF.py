#simple QuickFind algorithm
class UF:
        def __init__(self, N):
                self.idTab = []
                for i in xrange(N):
                        self.idTab.append(i)

        def connected(self, p, q):
                return self.idTab[p] == self.idTab[q]

        def union(self, p, q):
                pid = self.idTab[p]
                qid = self.idTab[q]
                for i in xrange(len(self.idTab)):
                        if (self.idTab[i] == pid):
                                self.idTab[i] = qid

