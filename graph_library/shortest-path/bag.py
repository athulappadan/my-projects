# simple bag implementation

class Bag:
        def __init__(self):
                self.bag = []

        def add(self,x):
                self.bag.append(x)

        def size(self):
                return len(self.bag)

        def isEmpty(self):
                return self.size == 0

        def get_item(self, i):
                return self.bag[i]

        def iter_bag(self):
                for i in xrange(self.size()):
                        yield self.get_item(i)

