class Tuple:
        def __init__(self, v, dist):
                self.v = v
                self.dist = dist

class PQ:
        def __init__(self):
                self.pq = [-1]

        def N(self):
                return len(self.pq) - 1

        def isEmpty(self):
                return self.N() == 0

        def swim(self, k):
                while (k > 1 and self.more(k/2, k)):
                        self.exch(k, k/2)
                        k = k/2

        def insert(self, v, dist):
                new = Tuple(v, dist)
                self.pq.append(new)
                self.swim(self.N())

        def sink(self, k):
                while (2*k <= self.N()):
                        j = 2*k
                        if (j < self.N() and (j+1) < self.N() and self.more(j, j+1)):
                                j += 1
                        if (not self.more(k, j)): break
                        self.exch(k, j)
                        k = j

        def delMin(self):
                mini = self.pq[1]
                self.exch(1, self.N())
                self.pq.pop()
                self.sink(1)

                return mini.v

        def more(self, i, j):
                return self.pq[i].dist > self.pq[j].dist

        def exch(self, i, j):
                temp = self.pq[i]
                self.pq[i] = self.pq[j]
                self.pq[j] = temp

        def contains(self, vertex):
                for tup in self.pq[1:]:
                        if (tup.v == vertex):
                                return True
                return False

        def decreaseKey(self, vertex, new_dist):
                for tup in self.pq[1:]:
                        if (tup.v == vertex):
                                tup.dist = new_dist

