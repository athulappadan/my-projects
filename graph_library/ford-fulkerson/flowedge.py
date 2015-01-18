class FlowEdge:
        def __init__(self, v, w, capacity):
                self.v = v
                self.w = w
                self.capacity = capacity
                self.flow = 0

        def fromV(self):
                return self.v

        def toV(self):
                return self.w

        def capacity(self):
                return self.capacity

        def flow(self):
                return self.flow

        def other(self, vertex):
                if (vertex == self.v):
                        return self.w
                else:
                        return self.v

        def residualCapacityTo(self, vertex):
                if (vertex == self.v):
                        return self.flow
                else:
                     return self.capacity - self.flow

        def addResidualFlowTo(self, vertex, delta):
                if (vertex == self.v):
                        self.flow -= delta
                else:
                        self.flow += delta


e1 = FlowEdge(0, 1, 2.0)
e2 = FlowEdge(0, 2, 3.0)       
e3 = FlowEdge(1, 3, 3.0)
e4 = FlowEdge(1, 4, 1.0)
e5 = FlowEdge(2, 3, 1.0)
e6 = FlowEdge(2, 4, 1.0)
e7 = FlowEdge(3, 5, 2.0)
e8 = FlowEdge(4, 5, 3.0)
